IoT Mottu - Projeto de Monitoramento

📝 Proposta e Funcionalidades

Este projeto consiste em um sistema de monitoramento de IoT para motocicletas, desenvolvido como parte do Challenge da FIAP. A solução utiliza um simulador em Python para gerar e enviar dados de telemetria em tempo real, que são enviados via protocolo MQTT para um dashboard de monitoramento (Node-RED).

As principais funcionalidades do sistema incluem:

Simulação de Dispositivos: Um script em Python simula três dispositivos IoT simultaneamente, enviando dados de distância, estado e busca ativa.

Coleta e Visualização em Tempo Real: O Node-RED recebe os dados via MQTT e os exibe em um dashboard interativo. O painel apresenta a telemetria em tempo real através de um medidor (gauge), um gráfico de linha e um texto de status.

Persistência de Dados: Todos os dados de telemetria são armazenados em um banco de dados MySQL, garantindo que o histórico de informações seja salvo para análise posterior.

👩‍💻 Integrantes do Grupo

Enzo Prado Soddano — RM557937
Lucas Resende Lima — RM556564
Vinicius Prates Altafini — RM556183


Link do projeto no workwi: https://wokwi.com/projects/442734327702711297 

Link do video: https://youtu.be/3Dg2IjTPFjQ
