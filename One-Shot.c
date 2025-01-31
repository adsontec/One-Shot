#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas
#include "pico/time.h"   // Biblioteca para gerenciamento de temporizadores e alarmes

// Define o LEDs de saída
#define GPIO_RED_LED 11
#define GPIO_YELLOW_LED 12
#define GPIO_GREEN_LED 13

// Define o Button como entrada
#define BUTTON_PIN 5

// Conexão dos pinos GPIO
const uint8_t GPIOs[] = {GPIO_RED_LED, GPIO_YELLOW_LED, GPIO_GREEN_LED};

// Varialvel Global
bool led_active = false;
absolute_time_t turn_off_time;

// Protótipo de Função
void inicializar_led();
void set_leds(bool red, bool yellow, bool green);
void inicializar_button();

int64_t turn_off_callback1(alarm_id_t id, void *user_data);
int64_t turn_off_callback2(alarm_id_t id, void *user_data);
int64_t turn_off_callback3(alarm_id_t id, void *user_data);

int main() {
  stdio_init_all();
  inicializar_led();
  inicializar_button();

  while(1){
    if (gpio_get(BUTTON_PIN) == 0 && !led_active) {
        sleep_ms(50); // Atraso para debounce

        // Verifica novamente o estado do botão após o debounce.
        if (gpio_get(BUTTON_PIN) == 0) {
            set_leds(1,1,1);

            led_active = true;

            add_alarm_in_ms(300, turn_off_callback1, NULL, false);
            add_alarm_in_ms(600, turn_off_callback2, NULL, false);
            add_alarm_in_ms(900, turn_off_callback3, NULL, false);
            
            led_active = false;
        }
    }
  }
}

// Função para inicializar saídas dos LEDs
void inicializar_led(){
   for (int i = 0; i < 3; i++){
    gpio_init(GPIOs[i]);
    gpio_set_dir(GPIOs[i], GPIO_OUT);
  }
}

//Função ligar LEDs
void set_leds(bool red, bool yellow, bool green){
	gpio_put(GPIO_RED_LED,red);
	gpio_put(GPIO_YELLOW_LED,yellow);
	gpio_put(GPIO_GREEN_LED,green);
}

// Função para inicializar a entrada do BUTTON_PIN
void inicializar_button(){
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    // Habilita o resistor pull-up interno
    gpio_pull_up(BUTTON_PIN); 
}

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback1(alarm_id_t id, void *user_data) {
    gpio_put(GPIO_RED_LED, false);

    return 0;
}

int64_t turn_off_callback2(alarm_id_t id, void *user_data) {
    gpio_put(GPIO_YELLOW_LED, false);

    return 0;
}

int64_t turn_off_callback3(alarm_id_t id, void *user_data) {
    gpio_put(GPIO_GREEN_LED, false);

    return 0;
}