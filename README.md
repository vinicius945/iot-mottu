# IoT Mottu - Projeto de Monitoramento de Telemetria

## 📝 Proposta e Funcionalidades
Este projeto implementa uma solução de monitoramento de Internet das Coisas (IoT) para motocicletas, seguindo os requisitos do Challenge de Análise e Desenvolvimento de Sistemas da FIAP. O sistema foi projetado para capturar, processar e persistir dados de telemetria em tempo real.

A arquitetura da solução é composta pelos seguintes módulos e funcionalidades:

* **Módulo de Geração de Dados (Python):** Um script em Python, agindo como um agente simulador, emula o envio de telemetria de três dispositivos distintos. Os dados, formatados em JSON, são transmitidos para um broker MQTT, contendo métricas como distância, estado e um timestamp.
* **Módulo de Processamento e Visualização (Node-RED):** A plataforma Node-RED atua como o middleware, inscrevendo-se no tópico MQTT para consumir os dados. O fluxo de trabalho foi configurado para:
    * **Dashboard Interativo:** Exibir a telemetria em tempo real por meio de um medidor (gauge), um gráfico de linha e um painel de texto, proporcionando uma visualização clara das condições operacionais dos dispositivos.
    * **Persistência de Dados:** Conectar-se a um banco de dados MySQL para persistir cada registro de telemetria, garantindo a disponibilidade de um histórico de dados para análises retrospectivas.
* **Armazenamento de Dados (MySQL):** Um banco de dados relacional MySQL é utilizado para o armazenamento durável dos registros de telemetria. A arquitetura de banco de dados foi otimizada para inserções eficientes, com a tabela `historico` servindo como repositório principal de dados.

---

## 🏛️ Arquitetura do Projeto
A arquitetura do sistema segue um modelo de publicação/inscrição (publish/subscribe) baseado em um broker de mensagens, garantindo a separação e escalabilidade dos componentes.

O fluxo de dados opera da seguinte forma:

1.  **Geração e Publicação:** O **Simulador Python** (ou o hardware ESP32) atua como **publisher**, coletando dados de telemetria e publicando-os em um tópico específico no **Broker MQTT (HiveMQ)**.
2.  **Processamento e Visualização:** A plataforma **Node-RED** atua como **subscriber**, recebendo as mensagens do Broker. O fluxo de trabalho processa os dados, exibe-os em um **Dashboard** interativo e os encaminha para a camada de persistência.
3.  **Persistência e Consulta:** O **Banco de Dados MySQL** armazena todos os registros de telemetria.



+----------------+      +--------------+      +----------------+
| Dispositivo    |  --> | Broker MQTT  |  --> | Node-RED       |
| (Simulador)    |      | (HiveMQ)     |      | (Dashboard)    |
+----------------+      +--------------+      +----------------+
|                      |
v                      v
(Inserção de Dados)    (Consulta de Dados)
|                      |
v                      v
+----------------------+
| Banco de Dados MySQL |
+----------------------+









