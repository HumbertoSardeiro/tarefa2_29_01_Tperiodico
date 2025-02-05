#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/time.h"

// Definição dos pinos dos LEDs
#define LED_RED   11
#define LED_YELLOW 12
#define LED_GREEN 13

int num = 0;

// Definindo a enumeração para os estados do semáforo
typedef enum {
    VERMELHO,  // LED vermelho
    AMARELO,   // LED amarelo
    VERDE      // LED verde
} semaforo_estado;

// Variável para controlar o estado do semáforo
semaforo_estado estado = VERMELHO;  // Inicializa o estado como VERMELHO

// Função que mapeia o estado para a string correspondente
const char* estado_para_string(semaforo_estado estado) {
    switch (estado) {
        case VERMELHO: return "VERMELHO";
        case AMARELO: return "AMARELO";
        case VERDE: return "VERDE";
    }
}

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do semáforo a cada chamada
    switch (num) {
        case 1: // Se a luz estava verde faz esse case
            gpio_put(LED_RED, 1);    // Acende o LED vermelho
            gpio_put(LED_YELLOW, 0); // Desliga o LED amarelo
            gpio_put(LED_GREEN, 0);  // Desliga o LED verde
            estado = VERMELHO;        // Próximo estado é o AMARELO
            num = 3;
            break;
        case 2: // Se a luz estava amarela faz esse case
            gpio_put(LED_RED, 0);    // Desliga o LED vermelho
            gpio_put(LED_YELLOW, 0); // Desliga o LED amarelo
            gpio_put(LED_GREEN, 1);  // Acende o LED verde
            estado = VERDE;       // Próximo estado é o VERMELHO
            num = 1;
            break;
        case 3: // Se a luz estava vermelha faz esse case
            gpio_put(LED_RED, 0);    // Desliga o LED vermelho
            gpio_put(LED_YELLOW, 1); // Acende o LED amarelo
            gpio_put(LED_GREEN, 0);  // Desliga o LED verde
            estado = AMARELO;          // Próximo estado é o VERDE
            num = 2;
            break;
    }

    return true; // Retorna true para continuar o temporizador
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Inicialização dos pinos dos LEDs
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_put(LED_RED, 1);    // Acende o LED vermelho
    gpio_put(LED_YELLOW, 0); // Desliga o LED amarelo
    gpio_put(LED_GREEN, 0);  // Desliga o LED verde
    estado = VERMELHO;        // Inicia o semáforo no estado AMARELO
    num = 3;

    // Inicializa o temporizador repetitivo
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        sleep_ms(1000); // A cada 1 segundo, imprime o estado no terminal
        printf("Semáforo em: %s\n", estado_para_string(estado)); // Exibe o estado como string
    }

    return 0;
}