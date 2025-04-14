#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
*/
int main(void) {
	// Inicializo el USB
    stdio_init_all();
	// Habilito el GPIO25 (LED)
    gpio_init(PICO_DEFAULT_LED_PIN);
    // GPIO25 como salida
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

	// Mensaje por USB
	printf("\nHola mundo!\n");

    while (true) {
    	// Prendo LED
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        // Mensaje por USB
        printf("LED prendido\n");
        // Demora
        sleep_ms(500);
        // Apago LED
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
		// Mensaje por USB
		printf("LED apagado\n");
		// Demora
        sleep_ms(500);
    }
    return 0;
}
