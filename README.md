# Projeto Semáforo Periódico com Raspberry Pi Pico W

## Descrição

Este projeto simula o funcionamento de um semáforo com **Raspberry Pi Pico W** utilizando **três LEDs** (vermelho, amarelo e verde). O semáforo alterna a cada 3 segundos entre os três estados (vermelho, amarelo e verde) para representar a mudança de sinal de um semáforo real. O controle de alternância dos LEDs é feito com o uso de um temporizador periódico, ajustado para um atraso de 3 segundos (3000ms).

### Fluxograma de Funcionamento:

1. **Vermelho** (LED vermelho aceso)
2. **Amarelo** (LED amarelo aceso)
3. **Verde** (LED verde aceso)

A mudança de estado dos LEDs acontece a cada 3 segundos, e o estado atual é impresso no terminal a cada 1 segundo, indicando a cor do semáforo atual.

## Componentes Utilizados

- 1x **Raspberry Pi Pico W**
- 3x **LEDs** (Vermelho, Amarelo e Verde)
- 3x **Resistores de 330Ω**
- Fios de conexão

## Requisitos

1. O semáforo começa no estado **vermelho**, alternando entre vermelho, amarelo e verde.
2. A cada 3 segundos, o temporizador altera o estado dos LEDs.
3. O código usa a função `add_repeating_timer_ms()` para implementar o temporizador periódico.
4. A cada segundo, o estado do semáforo é impresso no terminal.
5. Este código foi projetado para simulação na ferramenta **BitDogLab** e pode ser adaptado para ser executado no **Wokwi**.

## Fluxo de Funcionamento

A sequência de LEDs é controlada por um temporizador periódico que alterna entre os estados do semáforo:

1. **Vermelho**: LED vermelho aceso, outros apagados.
2. **Amarelo**: LED amarelo aceso, outros apagados.
3. **Verde**: LED verde aceso, outros apagados.

Cada estado dura 3 segundos, e a cada 1 segundo, o sistema imprime o estado atual do semáforo no terminal.
