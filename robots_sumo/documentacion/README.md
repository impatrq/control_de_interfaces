# Documentación del Proyecto: ChupiCup

Repositorio designado para el registro, la documentación y el desarrollo del robot **ChupiCup**

---

##  Bitácora de Progreso y Desarrollo

###  Investigamos
* **Programación Inicial:** Martín, Sebas y Benjamín intentaron desarrollar un código de manera autónoma guiándose de recursos en video.
  * 🔗 [Referencia de código en YouTube](https://www.youtube.com/watch?v=1-qjMS6C960)
* **Planificación:** Visualizamos material audiovisual para la elaboración correcta de diagramas.
  * 🔗 [Guía de diagramas en YouTube](https://www.youtube.com/watch?v=1-qjMS6C960)
* **Inventario:** Revisamos el kit completo, contando y verificando cada una de las piezas una por una.

---

###  Ensamblaje y las fallas que detectamos
* **Prueba de Armado:** Construimos el prototipo inicial para detectar posibles fallos estructurales.
* **Problemas Detectados:** Encontramos holguras (*juegos*) entre los motores y las piezas de acople.
* **Validación:** Afirmamos y consolidamos la idea conceptual del robot.
* **Obstáculos:** Surgieron inconvenientes técnicos relacionados con la computadora durante las pruebas de código.

---

###  Investigación Teórica (Puente H)
Martín, Sebas y Benjamín investigaron a fondo sobre el **Puente H**, descubriendo que:
> Es un circuito eléctrico que permite a un motor de corriente continua (DC) girar en ambos sentidos y controlar su velocidad de forma precisa.

---

###   Mejoramos y Actualizamos 
*Nos propusimos optimizar las bitácoras, la documentación, el diseño del modelo y el firmware del robot.*

####  logramos:
* Trazado exitoso del diagrama.
* Mejora sustancial en la estructura de las bitácoras en sus respectivas ramas y en la documentación general.
* Modelo 3D prácticamente listo para enviar a impresión (diseñado en **Tinkercad**).
* Desarrollo de la base del código asistido mediante **ChatGPT**.

---

> *Proyecto en desarrollo constante.* ⚙️
[Ver proyecto en Tinkercad](https://www.tinkercad.com/things/jq6sLEZiAXH-incredible-turing-blad)
### Explicación del diseño del robot

El robot está diseñado con una forma de rampa en la parte delantera para poder meterse por debajo de los robots rivales y levantarlos o desplazarlos. La idea principal es aprovechar su velocidad para llegar rápidamente hasta el oponente y empujarlo hacia afuera del área de combate.

Cuenta con **dos ruedas a cada lado**, lo que le permite tener buena estabilidad y tracción al momento de avanzar y empujar. Los motores están ubicados dentro de la estructura para protegerlos y transmitir la fuerza directamente a las ruedas.

Además, la **batería, la protoboard y los demás componentes electrónicos están colocados dentro de la rampa**, para protegerlos de golpes durante el enfrentamiento y mantener el centro de gravedad bajo. De esta manera, el robot tiene mayor estabilidad y es más difícil que el rival pueda volcarlo.

En conclusión, el diseño busca combinar **velocidad, estabilidad y capacidad de empuje**, con el objetivo de alcanzar rápidamente a los robots rivales, introducir la rampa debajo de ellos y sacarlos del área de combate.

### Carcasa del robot

La carcasa de nuestro robot estará fabricada principalmente de **plástico rígido**, ya que es un material liviano, resistente y fácil de trabajar. Elegimos este material porque permite reducir el peso del robot, haciendo que los motores puedan moverlo con mayor facilidad y alcanzar una buena velocidad. Además, el plástico es suficientemente resistente para soportar los golpes que puede recibir durante el enfrentamiento.

La carcasa tendrá una **base, laterales, parte superior y una rampa inclinada en la parte delantera**. En su interior estarán protegidos la batería, la protoboard, los motores y los demás componentes electrónicos. De esta manera, los componentes estarán protegidos de posibles golpes y movimientos durante el funcionamiento.

La parte más importante será la **rampa delantera**, que estará diseñada para introducirse por debajo de los robots rivales. Al avanzar, el robot podrá aprovechar su velocidad y la fuerza de sus motores para empujar al rival y sacarlo del área de combate. Las cuatro ruedas, dos de cada lado, proporcionarán estabilidad y tracción para poder realizar estos movimientos.

En conclusión, la carcasa de plástico busca combinar **bajo peso, resistencia y protección de los componentes**, mientras que su forma de rampa permite que el robot cumpla su función principal: avanzar rápidamente, colocarse debajo del robot rival y empujarlo fuera del área de combate.

### Portapilas

El portapilas utiliza 4 pilas tipo AAA (UM-4). Cada pila proporciona aproximadamente 1,5 V, por lo que, al estar conectadas en serie, el voltaje total es de 6 V.

La conexión en serie hace que los voltajes de las cuatro pilas se sumen:

1,5 V + 1,5 V + 1,5 V + 1,5 V = 6 V.

### Puente H
![diagrama.jpeg](https://megatronica.cc/wp-content/uploads/2022/02/L298N-ECUADOR-CONECCION-ARDUINO-DRIVER-PUENTE-H-L298N-Modulo-Driver-Motor-A-pasos-PINOUT_1.jpg)

###las conexiones
las conexiones que van desde la Raspberry Pi Pico W hacia el Puente H (y los motores/alimentación) se distribuyen de la siguiente manera:
###1 Entradas de Control de Motores (Desde la Pico W hacia el Puente H)
Las líneas de control de dirección salen de los pines GPIO de la Raspberry Pi Pico W y se conectan a los pines de entrada del puente H:
 * GPIO 2 se conecta a IN1
 * GPIO 3 se conecta a IN2
 * GPIO 6 se conecta a IN3
 * GPIO 4 se conecta a IN4
###2 Habilitadores (Enable - ENA / ENB)
En el plano se observa que las líneas de habilitación de velocidad están unidas y conectadas a pines de control:
 * ENB está conectado a GPIO 5
 * ENA está conectado a GPIO 7
   
###3 Salidas a los Motores
 * OUT1 y OUT2 del Puente H van conectados a los terminales positivo (+) y negativo (-) del Motor 1 (M1).
 * OUT3 y OUT4 del Puente H van conectados a los terminales del Motor 2 (M2).
   
###4 Alimentación y Tierra (GND)
 * El pin de GND de la Raspberry Pi Pico W se conecta a la línea de tierra común que va al GND del Puente H y al negativo de la fuente de alimentación.
 * El pin de 5V (o alimentación principal) alimenta el sistema y se conecta al pin de voltaje del Puente H.
