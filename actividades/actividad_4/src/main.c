#include <stdio.h>
#include "pico/stdlib.h"

/**
 * Funcion que se llama cada vez que se cumple el tiempo del Timer
 */
bool timer_callback(repeating_timer_t *timer) {

	// Resolver el LED shifting
}


/**
 * @brief Programa principal
*/
int main(void) {
	// Inicializo el USB
	stdio_init_all();
	// Demora para esperar la conexion
	sleep_ms(1000);

	// Inicializacion de GPIO con gpio_init()

	// Configuracion de entrada/salida con gpio_set_dir()

	// Inicializacion del Timer
	repeating_timer_t timer;


	while (true) {
		// Verificar cambio de direccion

	}
	return 0;
}
