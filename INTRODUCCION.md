# Introducción a Control de Interfaces
## Microcontroladores
### Microcontroladores (MCU) y Microprocesadores (MPU)

Los microcontroladores o µC, son circuitos integrados diseñados para aplicaciones de control específicas. Integran en un mismo dispositivo un núcleo de procesamiento, memorias y periféricos (temporizadores, conversores analógico-digitales, pines de entrada/salida e interfaces de comunicación). Nos permiten implementar sistemas embebidos sin la necesidad de agregar tantos componentes externos, donde podremos combinar distintos módulos (hardware) para que el sistema interactúe con el exterior, junto con algoritmos de control y manejo de datos (software).

Los microprocesadores o µP, solo componen la unidad de procesamiento del sistema, por lo tanto al utilizarlos, debemos agregar los distintos periféricos y memorias para obtener un sistema funcional. Son utilizados en el armado de computadoras.

### Memorias
En informática, las memorias son aquel espacio donde podremos almacenar datos. Existen distintos tipos, pero las agrupamos en dos grandes grupos, **Memorias Volátiles** (pierden su contenido al interrumpir su suministro eléctrico) y **Memorias No Volátiles** (conservan la información almacenada, incluso luego de perder el suministro de energía).

#### Memorias Volátiles
- ##### RAM (Random Access Memory)
    Este es el espacio de memoria que guarda los datos que consultarán o almacenarán los distintos componentes durante la ejecución de programas. Como lo indica su nombre, los datos se guardan de forma aleatoria para que el acceso sea más rápido. Esto significa que, cualquier parte de la memoria puede ser escrita o leída directamente.
    Mientras más RAM tenga un dispositivo, más datos podrá almacenar de forma aleatoria, lo que le permitirá usar más programas al mismo tiempo, o procesar en menor tiempo programas "más pesados".
    Una vez pierda su suministro eléctrico, todos los datos guardados allí se perderán.

#### Memorias No Volátiles
Aquí guardamos datos que necesitan ser conservados de forma permanente, como lo son el firmware, programas, archivos, el sistema operativo o la BIOS (Basic Input/Output System) del sistema. La encargada de guardar estos datos suele ser la memoria Flash.

### Arquitecturas
A la hora de operar, los microcontroladores deben transferir datos y comunicarse entre la unidad de procesamiento y sus memorias. La configuración que utilicen es su **Arquitectura de Acceso a Memoria**.
Existen dos tipos:
- Von Neumann: Esta arquitectura utiliza una misma memoria para almacenar datos e intrucciones. Nos deja un solo bus de datos comunicando la memoria con la unidad de procesamiento. Fue muy usada hasta que se descubrieron las ventajas de la arquitectura Harvard. 
- Harvard: Esta arquitectura utiliza memorias separadas para datos y programas o instrucciones, de forma que tenemos dos buses de datos distintos trabajando a la vez, siendo más rápida que la Von Neumann. Esta es la que utilizan la mayoría de los microcontroladores en la actualidad.

De acuerdo a cómo sean las instrucciones que utiliza nuestro sistema, nos encontramos con los distintos tipos de **Arquitecturas del conjunto de instrucciones** (Instruction Set Architecture).
Existen dos tipos:


- CISC (Complex Instruction Set Computer):
    Utilizan instrucciones complejas, es decir, pueden realizar varias operaciones al mismo tiempo, por lo que una sola instrucción puede resolver una tarea relativamente grande.
    Debido a esta complejidad, estas instrucciones suelen requerir varios ciclos de clock para ejecutarse.

- RISC (Reduced Instruction Set Computer)
    Utilizan instrucciones más simples. Cada instrucción realiza una operación muy específica, por lo que para resolver una misma tarea se necesitan varias instrucciones pequeñas.
    Estas instrucciones suelen completarse en un solo ciclo de clock.

Estas arquitecturas se comportan de una u otra forma debido al hardware de cada procesador. Pensando en que cada instrucción que nosotros le damos a un procesador tiene que atravesar un camino distinto dentro del mismo (electrónicamente), un procesador que solo maneje instrucciones básicas (RISC), tendrá "menos caminos" que un CISC. Por otro lado, para determinadas tareas, donde solamente repetiremos la misma instrucción compleja muchas veces, tal vez nos conviene tenerla simplificada en un solo camino.
También podemos comparar los espacios de memoria que ocupa cada una, ya que, una instrucción ocupa la misma cantidad de espacio, siendo más o menos compleja.

### Entradas y salidas

### Protocolos de comunicación
#### ¿Qué son?
#### Los más usados:
## Software
### Manejo de versiones
### Git
### Uso de Git en la computadora
### GitHub
### README
## Visual Studio Code (VSC)
### IDE
### Extensiones de VSC
### Extensión Raspberry Pi Pico
