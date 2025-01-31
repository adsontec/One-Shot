## 🚦 Temporizador usando One Shot ⏲️
Este projeto demonstra como usar o Raspberry Pi Pico W para fazer um semáforo de LEDs com butão usando um temporizador One Shot
que permiter o LED fica piscando.
## Funcionalidade:
Ao presionar o botão será acionado os LEDs (sinais do semáforo) deve iniciar na cor vermelha 🔴, alterando para amarela 🟡 e, em seguida, verde 🟢
## Requisitos de Hardware:
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω
- Buttton (Pushbutton)
## Requisitos de Software:
- Instalar o Visual Studio Code
- Instalar a extensão Wokwi no VSCode
- Instalar os pacotes do Pico SDK
## Pinos GPIO dos LEDs
- LED Vermelho: GPIO 11
- LED Amarelo: GPIO 12
- LED Verde: GPIO 13
- Button: GPIO 5
## Explicação do Código:
- **stdio_init_all()**: Inicializar comunicação padrão
- **inicializar_led()**: Inicializar as configurações dos pinos dos LEDs como saída
- **inicializar_button()**: Inicializar a entrada do BUTTON_PIN e habilita o resistor pull-up interno
- **turn_off_callback1(alarm_id_t id, void *user_data)**: Função de callback para desligar o LED após o tempo programado
- **add_alarm_in_ms(300, turn_off_callback1, NULL, false)**: Agendar para desligar o LED em 300 ms
## Produção do Vídeo

https://github.com/user-attachments/assets/aa1839ee-6c12-4396-9cc6-dd514da42443


![image](https://github.com/user-attachments/assets/1e7ff3f0-080c-4b58-a68e-2762ef6c1719)




