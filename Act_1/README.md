# Actividad 1

La idea es familiarizarse con la estructura basica de un programa en lenguaje C, los pasos necesarios para compilar y flashear y otras practicas comunes que vamos a usar en el laboratorio.

### Consigna

1. Crear un nuevo proyecto dentro de este directorio que se llame `actividad_1`.
2. Copiar en el programa principal el código siguiente:

```c
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  cyw43_arch_init();

  // Mensaje por USB
  printf("\nHola mundo!\n");

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    printf("LED prendido\n");
    // Demora
    sleep_ms(500);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Mensaje por USB
    printf("LED apagado\n");
    // Demora
    sleep_ms(500);
  }
  return 0;
}
```

3. Compilar y flashear el programa.
4. Abrir una comunicacion por consola para ver los mensajes del USB.
5. Hacer cambios en el programa para que el parpadeo del LED sea cada 1 segundo. Compilar y volver a flashear.
6. Hacer cambios en el programa para que el mensaje sea _"Hola [NOMBRE]!"_. Compilar y volver a flashear. Verificar el resultado en la consola.
7. Seguir las instrucciones para subir esta actividad a GitHub 