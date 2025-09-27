import paho.mqtt.client as mqtt
import json
import time
import random
from datetime import datetime

# Configurações do Broker MQTT
BROKER = "broker.hivemq.com"
PORT = 1883
TOPIC = "motos/telemetria"

# Lista de dispositivos a serem simulados
dispositivos = ["moto1", "moto2", "moto3"]

def on_connect(client, userdata, flags, rc):
    """Callback de conexão."""
    if rc == 0:
        print("Conectado ao broker MQTT!")
    else:
        print(f"Falha na conexão, código de retorno: {rc}")

def on_publish(client, userdata, mid):
    """Callback de publicação."""
    print(f"Mensagem {mid} publicada com sucesso.")

def simular_dados():
    """Gera e publica dados de telemetria para os dispositivos."""
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_publish = on_publish
    
    # Conecta ao broker
    client.connect(BROKER, PORT, 60)
    
    # Inicia um loop em segundo plano para manter a conexão
    client.loop_start()

    try:
        while True:
            for dispositivo in dispositivos:
                # Gera dados aleatórios
                distancia = round(random.uniform(0.0, 100.0), 2)
                estado = "Normal"
                if distancia > 80:
                    estado = "Alerta"
                elif distancia < 20:
                    estado = "Perigo"
                
                busca = bool(random.getrandbits(1)) # True ou False
                
                # Cria a carga de dados no formato JSON
                payload = {
                    "dispositivo": dispositivo,
                    "distancia": distancia,
                    "estado": estado,
                    "timestamp": datetime.now().isoformat(),
                    "busca": busca
                }
                
                # Converte o dicionário para uma string JSON
                payload_json = json.dumps(payload)
                
                # Publica a mensagem no tópico
                print(f"Enviando para {dispositivo}: {payload_json}")
                client.publish(TOPIC, payload_json, qos=0)
            
            # Espera 5 segundos para a próxima rodada de envio
            time.sleep(5)
            
    except KeyboardInterrupt:
        print("Simulação encerrada pelo usuário.")
    
    finally:
        client.loop_stop()
        client.disconnect()

if __name__ == "__main__":
    simular_dados()