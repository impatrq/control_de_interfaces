#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
// Declaracion de variables
    int LedOn = 0;
    int LedOff = 0;

  // Mensaje por USB
  printf("\nHola mundo!\n");

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Suma de feliz
    LedOn += 1;
    // Mensaje por USB
    printf("LED esta feliz\n");
    // Mensaje de encendidos
    printf("La cantidad de encendidos son: %d\n\n", LedOn);
    // Demora
    sleep_ms(15423);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Suma de triste
    LedOff += 1;
    // Mensaje por USB
    printf("LED esta triste\n");
    // Mensaje de apagados
    printf("La cantidad de apagados son: %d\n\n", LedOff);
    // Demora
    sleep_ms(200);
  }
  return 0;
}