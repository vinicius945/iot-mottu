#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h> // Adicione esta linha

// Configurações Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configuração MQTT
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "motos/telemetria";

// Pinos LEDs
const int ledAlarme = 0;
const int ledTrava = 2;
const int ledNotificacao = 4;

// Sensor ultrassônico
const int trigPin = 12;
const int echoPin = 13;

// Botão de busca
const int botaoBusca = 5;

// MQTT Client
WiFiClient espClient;
PubSubClient client(espClient);

// Função para conectar Wi-Fi
void setupWiFi() {
  Serial.print("Conectando Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.print("IP: "); Serial.println(WiFi.localIP());
}

// Função para conectar MQTT
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 2s");
      delay(2000);
    }
  }
}

// Função para medir distância ultrassônica
float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duracao = pulseIn(echoPin, HIGH);
  float distancia = duracao * 0.034 / 2; // cm
  return distancia;
}

void setup() {
  Serial.begin(115200);

  pinMode(ledAlarme, OUTPUT);
  pinMode(ledTrava, OUTPUT);
  pinMode(ledNotificacao, OUTPUT);
  pinMode(botaoBusca, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  setupWiFi();
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  float distancia = medirDistancia();
  String estadoMoto = (distancia < 20) ? "moto_presente" : "moto_ausente";
  bool buscaAtiva = (digitalRead(botaoBusca) == LOW);

  digitalWrite(ledAlarme, distancia >= 20);
  digitalWrite(ledTrava, distancia < 20);
  digitalWrite(ledNotificacao, distancia >= 20);

  StaticJsonDocument<200> doc;
  doc["timestamp"] = String(millis()/1000); // Removido o "s"
  doc["distancia"] = distancia;
  doc["estado"] = estadoMoto;
  doc["busca"] = buscaAtiva;
  doc["dispositivo"] = "MotoB"; // <-- Linha adicionada

  char jsonBuffer[200];
  serializeJson(doc, jsonBuffer, sizeof(jsonBuffer));

  Serial.println("Enviando MQTT: " + String(jsonBuffer));
  client.publish(mqttTopic, jsonBuffer);

  delay(1000);
}