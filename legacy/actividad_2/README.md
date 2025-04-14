# actividad_1

La idea es familiarizarse con la estructura basica de un programa en lenguaje C, los pasos necesarios para compilar y flashear y otras practicas comunes que vamos a usar en el laboratorio.

## Consigna

1. Abrir el directorio con el editor de texto correspondiente (Sublime Text, VS Code o nano en la terminal).
2. Ver el archivo `src/main.c` y observar la estructura del programa.
3. Compilar y flashear el programa. Seguir las instrucciones correspondientes para [VS Code con PlatformIO](#compilar-y-flashear-con-platformio) u [otros](#compilar-y-flashear-en-linux).
#### TODO
7. Seguir las [instrucciones](#subir-a-github) para subir esta actividad a GitHub.

## Compilar y flashear con PlatformIO

El proceso es bastante sencillo:

1. Vamos a tener que ir al menu de PlatformIO y vamos a buscar una opcion que diga **build** que va a compilarnos el programa.
2. Una vez compilado, vamos a alimentar la Raspberry Pi Pico manteniendo apretado el boton de **BOOTSEL**, la computadora deberia verla como una unidad de almacenamiento externa.
3. Vamos al menu de PlatformIO y vamos a buscar la opcion de **upload**.
4. Para ver lo que la Raspberry Pi Pico nos dice por el USB, vamos a buscar la opcion de **monitor** y deberiamos ver una consola.

## Compilar y flashear en Linux

El proceso requiere algo de nocion de algunos comandos de consola pero lo automatizamos en un archivo [Makefile](Makefile) para hacerlo mas facil.

1. Vamos a abrir una terminal con **Ctrl + Alt + T**.
2. Vamos a navegar hasta el directorio de la actividad moviendonos en el sistema de archivos con el comando **cd [directorio]**. Podemos usar **cd ..** para volver hacia atras y *ls* para ver que directorios tenemos disponibles para entrar.
3. Una vez que estemos dentro del directorio de la actividad, vamos a escribir:

```bash
make help
```

Esto va a darnos algunas instrucciones sobre que opciones podemos usar.

4. Ahora vamos a escribir el comando:

```bash
make
```

Esto va a realizar el proceso completo de compilacion, generando un directorio `build` con los binarios necesarios para flashear.

5. Si el paso anterior no tiro errores, vamos a conectar la Raspberry Pi Pico a la computadora apretando el boton de **BOOTSEL**, deberia aparecernos como una unidad de almacenamiento. Entonces vamos a escribir en la consola:

```bash
make flash
```

Lo que va a proceder a copiar el binario necesario en la Pico para flashearla.

Si por el contrario, el paso anterior tiro errores, vamos a corregirlos en nuestro `main.c` y vamos a correr el comando:

```bash
make build
```

Este va a volver a intentar compilar los archivos.

6. Para poder ver los mensajes del USB, vamos a abrir un monitor serial escribiendo:

```bash
make monitor
```

Esto nos va a abrir una comunicacion con la Raspberry Pi Pico donde podemos ver los mensajes que nos diga. Para salir de minicom, usamos la combinacion de teclas **Ctrl + A** y luego **Q**.

## Subir a GitHub

Una vez que tengamos terminada la actividad, con la consola ubicada en este directorio haremos lo siguiente:

1. Primero tenemos que configurar nuestros datos, para eso:

```bash
git config user.email "email@email.com" && git config user.name "Nombre Apellido"
```

2. Luego, vamos a agregar a _git_ el archivo que modificamos en la actividad, en este caso, el _main.c_ que se encuentra en el directorio _src_. Podemos verificar eso escribiendo:

```bash
git status
```

Para efectivamente agregar el cambio, vamos a escribir:

```bash
git add src/main.c
```

Si este paso trajo errores, es porque la ruta no coincide.

3. Vamos a hacer un commit para guardar el estado de nuestro repositorio. Para eso escribimos:

```bash
git commit -m "describo brevemente lo que hice"
```

Este mensaje debe ser corto pero dar informacion clara de que se hizo. Ejemplo: cambie el tiempo de demora a 200 ms.

4. Pusheamos los cambios a nuestro repositorio usando:

```bash
git push
```
