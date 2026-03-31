# Actividad 1.0

## Git y Fork

Para realizar esta actividad y las proximas, deberán [forkear o ramificar](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) este repositorio. Esto permite crear una copia de un repositorio existente y trabajar desde ahi.

1. Clonar el repositorio forkeado en la carpeta 

```bash
git clone URL
```

2. Abrir Visual Studio Code y Trabajar dentro de la carpeta Act_1

## Extensión Raspberry Pi Pico 

Este Plugin nos permitirá trabajar en proyectos C/C++ con nuestra Raspberry

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

## Github

Una vez modificado el archivo mandaremos los cambios a github utilizando la consola.

1. Primero tenemos que configurar nuestros datos, para eso:

```bash
git config user.email email@email.com
```

```bash
git config user.name "Nombre Apellido"
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