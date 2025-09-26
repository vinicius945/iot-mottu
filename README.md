IoT Mottu - Projeto de Monitoramento
📝 Proposta e Funcionalidades
Este projeto consiste em um sistema de monitoramento de IoT para motocicletas, desenvolvido como parte do Challenge da FIAP. A solução utiliza um simulador de hardware (Wokwi) para coletar dados de telemetria em tempo real, que são enviados via protocolo MQTT para um dashboard de monitoramento (Node-RED).

As principais funcionalidades do sistema incluem:

Coleta de Dados em Tempo Real: O simulador de ESP32 utiliza um sensor ultrassônico para medir a distância de um obstáculo, simulando a presença ou ausência da moto. Os dados são enviados via MQTT para um broker.

Visualização Interativa: O dashboard no Node-RED exibe a telemetria em tempo real através de um medidor (gauge) e um gráfico de linha, permitindo uma visualização clara do status da moto.

Persistência de Dados: Todos os dados de telemetria são armazenados em um banco de dados SQLite, garantindo que o histórico de informações seja salvo para análise posterior.


👩‍💻 Integrantes do Grupo
Enzo Prado Soddano — RM557937

Lucas Resende Lima — RM556564

Vinicius Prates Altafini — RM556183]
