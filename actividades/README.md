# actividades

## Actividad 1

La idea es familiarizarse con la estructura basica de un programa en lenguaje C, los pasos necesarios para compilar y flashear y otras practicas comunes que vamos a usar en el laboratorio.

### Consigna

1. Crear un nuevo proyecto dentro de este directorio que se llame `actividad_1`.
2. Copiar en el programa principal el código de la sección [Startup code](#startup-code).
3. Compilar y flashear el programa.
4. Abrir una comunicacion por consola para ver los mensajes del USB.
5. Hacer cambios en el programa para que el parpadeo del LED sea cada 1 segundo. Compilar y volver a flashear.
6. Hacer cambios en el programa para que el mensaje sea _"Hola [NOMBRE]!"_. Compilar y volver a flashear. Verificar el resultado en la consola.
7. Seguir las [instrucciones](#subir-a-github) para subir esta actividad a GitHub o subirlo a través de la extensión de VS Code.

### Startup code

```c
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
```

## Subir a GitHub

Una vez que tengamos terminada la actividad, con la consola ubicada en este directorio haremos lo siguiente:

1. Primero tenemos que configurar nuestros datos, para eso:

```bash
git config user.email "email@email.com" && git config user.name "Nombre Apellido"
```

2. Luego, vamos a agregar a _git_ el o los archivos que modificamos en la actividad. Podemos verificar eso escribiendo:

```bash
git status
```

Para efectivamente agregar el cambio, vamos a escribir:

```bash
git add FILE
```

Reemplazando `FILE` por el nombre del archivo que corresponda. Si este paso trajo errores, es porque la ruta no coincide.

3. Vamos a hacer un commit para guardar el estado de nuestro repositorio. Para eso escribimos:

```bash
git commit -m "describo brevemente lo que hice"
```

Este mensaje debe ser corto pero dar informacion clara de que se hizo. Ejemplo: cambie el tiempo de demora a 200 ms.

4. Pusheamos los cambios a nuestro repositorio usando:

```bash
git push
```
