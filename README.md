oT Mottu - Projeto de Monitoramento
📝 Proposta e Funcionalidades
Este projeto consiste em um sistema de monitoramento de IoT para motocicletas, desenvolvido como parte do Challenge da FIAP. A solução utiliza um simulador de hardware (Wokwi) para coletar dados de telemetria em tempo real, que são enviados via protocolo MQTT para um dashboard de monitoramento (Node-RED).

As principais funcionalidades do sistema incluem:

Coleta de Dados em Tempo Real: O simulador de ESP32 utiliza um sensor ultrassônico para medir a distância de um obstáculo, simulando a presença ou ausência da moto. Os dados são enviados via MQTT para um broker.

Visualização Interativa: O dashboard no Node-RED exibe a telemetria em tempo real através de um medidor (gauge) e um gráfico de linha, permitindo uma visualização clara do status da moto.

Persistência de Dados: Todos os dados de telemetria são armazenados em um banco de dados SQLite, garantindo que o histórico de informações seja salvo para análise posterior.

📁 Estrutura de Pastas
A estrutura do projeto está organizada para facilitar a navegação e a compreensão de cada componente da solução:

iot-mottu/
|-- c_plus_plus/
|   `-- main.cpp  # Código do ESP32 no Wokwi
|-- node_red/
|   `-- fluxo.json # JSON do fluxo do Node-RED
|-- docs/
|   `-- relatorio_sprint3.pdf # PDF de entrega da sprint
|-- videos/
|   `-- video_demonstracao.mp4 # Vídeo da demonstração do projeto
|-- .gitignore
|-- README.md
🔗 Link do Repositório GitHub
URL do Repositório: https://github.com/vinicius945/iot-mottu

👩‍💻 Integrantes do Grupo
Nome	RM	GitHub
Vinicius	[Seu RM]	https://github.com/vinicius945
[Nome do Integrante 2]	[RM do Integrante 2]	[Link do GitHub do Integrante 2]
[Nome do Integrante 3]	[RM do Integrante 3]	[Link do GitHub do Integrante 3]
