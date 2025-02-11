# Controle de servomotor com PWM
Tarefa da unidade 4, capítulo 7, promovida pelo EmbarcaTech.

<div align="center">  
  <img align="center" src= img/wokwi.png
  <p><em>Simulação no Wokwi</em></p>
</div>

### Requisitos
- Controlar um servomotor via PWM usando a GPIO 22. Gerar sinais de 50Hz (período de 20ms) e ajustar o ciclo ativo para posicionar o servomotor em 0°, 90° e 180°.
- Rotina para mover o servomotor suavemente entre 0° e 180°
- Experimentos com LED: Utilizar o LED RGB (GPIO 12) para testes (disponível no vídeo)
* Simular no Wokwi integrado ao VS Code.

### Funcionamento
1. O servomotor inicia com os ângulos:
- **180° =** 2400μs de pulso.
- **90° =** 1470μs de pulso.
- **0° =** 500μs de pulso.
2. O servomotor se move do início ao fim (0° e 180°), usando incrementos de 5μs no pulso e delay de 10ms.

### Instruções de uso
- É necessário instalar o SDK da Raspberry Pi Pico e realizar as configurações iniciais. [1]

Para ter acesso ao projeto, clone o repositório disponível na [plataforma GitHub](https://github.com/naylane/tarefa-U4C6).

Após clonar o repositório, no terminal, navegue até a pasta do projeto e execute os comandos:
```bash
mkdir build && cd build
cmake ..
make
```
Para testar com LED na Raspberry Pi Pico, altere o pino GPIO 22 por GPIO 12, conecte a BitDogLab no computador enquanto pressiona o botão `BOOTSEL` e rode o código pelo VS Code.

⚠️ **Observação:** também é possível simular a atividade pelo Wokwi no Visual Studio Code. Basta instalar a extensão e executar o arquivo 'diagram.json'.

Ou, se preferir, [clique aqui para ver a simulação no Wokwi Web](https://wokwi.com/projects/422603356971975681).

<div align="center">  
  <img align="center" src= img/led.jpg
  <p><em>Simulação com LED na BitDogLab</em></p>
</div>

### Tecnologias e Ferramentas utilizadas
- **Kit BitDogLab:**
  - Raspberry Pi Pico W
  - Servomotor (no simulador Wokwi)
  - LED RGB
  - Simulador Wokwi
- **Linguagem de programação:** C
- **Ambiente de Desenvolvimento:** Visual Studio Code

### Referências
- [1] Documentação do Raspberry Pi Pico W. Disponível em [www.raspberrypi.com](https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html)
- [2] [Documentação do SDK](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)
