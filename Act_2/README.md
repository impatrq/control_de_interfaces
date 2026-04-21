# Actividad 2.0

La idea es comenzar a familiarizarse con el uso de puertos digitales de entrada y salida de un microcontrolador.

### Consigna

1. Crear un nuevo proyecto dentro de este directorio que se llame `actividad_2`.
2. Copiar en el programa principal el código siguiente:

```c
#include <stdio.h>
#include "pico/stdlib.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  // Demora para esperar la conexion
  sleep_ms(1000);

  // Inicializacion de GPIO con gpio_init()

  /* Habilito el GPIO25 (LED)
  gpio_init(PICO_DEFAULT_LED_PIN);
  GPIO25 como salida
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
  Configuracion de entrada/salida con gpio_set_dir()

  */


  while (true) {

    /* Prendo LED
    gpio_put(PICO_DEFAULT_LED_PIN, 1);

    */

    // Resolver logica para GPIO20 -> GPIO6

    // Resolver logica para GPIO21 -> GPIO7

    // Resolver logica para GPIO22 -> GPIO8

  }
  return 0;
}
```
3. Configurar los GPIO de la siguiente forma:

<div align="center">

| GPIO | Configuración | Componente |
| --- | --- | --- |
| 6 | Salida | LED |
| 7 | Salida | LED |
| 8 | Salida | LED |
| 20 | Entrada | Pulsador |
| 21 | Entrada | Pulsador |
| 22 | Entrada | Pulsador |
 
</div>

4. Una vez configurado, resolver lo siguiente:
    - Cuando se apriete el pulsador en el GPIO20, el LED del GPIO6 debe encenderse. Cuando se suelte el pulsador, el LED debe apagarse.
    - Cada vez que se apriete el pulsador en el GPIO21, el LED del GPIO7 debe cambiar de estado, es decir, si estaba prendido, se apaga y si estaba apagado, se prende.
    - Mientras que el pulsador en el GPIO22 se mantenga apretado, el LED en el GPIO8 debe parpadear cada medio segundo. Cuando se suelte el pulsador, el LED debe quedar en el último estado.
5. Compilar y flashear el programa.
6. Seguir las [instrucciones](##Github) para subir esta actividad a GitHub.


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
