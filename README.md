# Matriz LED

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/ofMYB50ozew/0.jpg)](https://www.youtube.com/watch?v=ofMYB50ozew)


El LED es una fuente de luz constituida por un material semiconductor dotado de dos terminales. Es una alternativa rentable de bajo consumo en comparación con otras fuentes de luz como los bombillos o las lámparas fluorescentes.

Para este proyecto utilizamos LEDs blancos ultra brillantes que funcionan con un voltaje de 3.5v a 20mA diseñamos una matriz bastante sencilla que necesita una fuente de alimentación de 12v y 600mA para funcionar.

Usamos este simple circuito para encender 2 LEDs su corriente es de 22mA y nuestro reflector será de 50 LEDs así que pusimos el circuito 25 veces de la misma fuente, la corriente total de la matriz es de 550mA.

Usamos una placa fenólica de 5cm x 10cm donde acomodamos los LEDs con el programa proteus hicimos el diseño para la placa fenólica. Este diseño esta disponible en la carpeta [Circuito](https://github.com/skgadi/LED-dimmer/tree/master/Circuito).

![Circuito LED a 12V y 22mA](/Imagenes/circuito_led.jpg)

# APP Android

Para poder controlar cualquier proyecto con un Smartphone es necesario diseñar una app que tenga la tarea de enviar datos al microcontrolador.

Se usará una herramienta web creada por Google labs para crear la app que vamos a utilizar, APP inventor es una página web donde se puede diseñar una app de manera muy sencilla para después programarla con diagrama de bloques.

La app que diseñamos cuenta con 1 botón de conexión bluetooth este nos sirve para establecer una conexión entre el módulo HC-05 y nuestro Smartphone, 1 botón ON que envía un valor "A" al módulo HC-05, 1 botón OFF que envía un valor "B" y 1 slider que envía valores de entre "0" y "9". Este applicacion esta disponible en la carpeta [App](https://github.com/skgadi/LED-dimmer/tree/master/App).

![Applicación de Android](/Imagenes/dimer_bt.png)

# Arduino + BT

Arduino es una placa electrónica de código abierto basada en hardware y software fáciles de usar. Las placas Arduino pueden leer entradas (comandos recibidos por un módulo HC-05) y convertirla en una salida: encender un LED y variar la intensidad de luz del mismo.

Usaremos un microcontrolador Arduino para la realización de nuestro proyecto este se encargará de recibir por medio de comunicación serial comandos del módulo HC-05. El módulo HC-05 es ideal para utilizar en todo tipo de proyectos donde necesites una conexión inalámbrica bluetooth fiable y sencilla de utilizar.


La conexión con el microcontrolador es muy sencilla:

![conexion](/Imagenes/conexion.png)

Para accionar el LED usaremos una salida PWM del microntrolador. Es una señal cuadrada de alta frecuencia a la que se le puede cambiar el ancho de pulso, para un LED esta señal es como si encendiera y apagara a alta velocidad tan alta que no es visible para el ojo humano, sin embargo, se aprecia la disminución de luz en el LED.

Como la matriz que vamos a manejar funciona con 12v y la salida que maneja el microcontrolador es de 5v es necesario utilizar un transistor, para este proyecto usaremos un transistor MOSFET Tipo-n este tipo de transistor funciona como un interruptor que permanece abierto si no se le aplica voltaje a la compuerta, y se cierra al energizar la compuerta.

Esto nos sirve por que la PWM enviara una señal cuadrada al transistor y este funcionara como un interruptor encendiendo y apagando la señal GND de la matriz a la misma frecuencia que el arduino.

Como se menciona anteriormente es necesario una fuente de 12v para el matriz led, sin embargo, no se recomienda encender el microcontrolador con este voltaje, para seguridad usaremos un regulador de 5v para encender nuestro microcontrolador.

# Programación

Es necesario un código muy simple para la realización de este proyecto, el código utilizado fue el siguiente:

```javascript
int ledPin = 9; // usamos un pin PWM de salida al LED
byte lectura; // Declaramos una variable para guardar las lecturas del módulo hc-05

void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    Serial.begin(9600);
}
 
void loop() {
  
  if(Serial.available() &gt; 0){ //Si se recibe cualquier valor
       lectura = Serial.read(); //Guardar el valor en lectura
       if(lectura == 'A'){ //si la lectura es igual a "A"
        digitalWrite(ledPin, HIGH);//Encender el LED
       }
       else if(lectura == 'B'){ //si la lectura es igual a "B"
        digitalWrite(ledPin, LOW); //Apagar el LED
       }
       else{ //si se recibe cualquier valor excepto "A" y "B"
        lectura = map(lectura, 48, 57, 0, 9); //convertir valores de lectura de entre 48 y 57 a valores enteros entre 0 y 9
        Serial.print("Lectura: "); //escribir "Lectura: " en el monitor serial
        Serial.println(lectura); //escribir el valor de lectura en el monitor serial
        lectura = map(lectura, 48, 57, 0, 255); //convertir valores de lectura de entre 0 y 9 a valores enteros entre 0 y 255
        analogWrite(ledPin, lectura); //escribir analogamente en el pin de salida
      }
  }
}
```


# Diseño de Carcasa

Para crear el diseño de la carcasa para nuestro proyecto utilizamos el programa solidwork diseñamos las piezas por partes  comenzando con la base. Principalmente comenzamos midiendo la baquelita y el arduino y así saber la medida  que nuestro circuito necesita para estar fijo, la medida de profundidad es de 60 mm,  después calcular la distancia en que colocaríamos la lámpara led y el arduino con una altura de 35 mm para la lámpara y al fondo, que son 55 mm colocamos el arduino. Para la mica diseñamos dos pestañas haciéndolas parecer un riel de 4 mm de altura para insertar la mica de la cual las medidas son de largo 10.5 mm, de ancho 7.5 mm y de grosor de 3 mm, para finalizar las extruimos a 120 mm de largo.

Después diseñamos las tapas de la carcasa con una longitud que cubriera toda la carcasa de 80 mm  de ancho de la parte de superior, 55 mm  en la parte inferior y una con una altura de 60 mm  y luego lo extruimos con un grosor de 4 mm.

Para finalizar con todo  el diseño creamos al último el arco que sostiene la carcasa de la lámpara con una longitud de 130 mm, una altura de 70mm y una anchura de 3 mm, para finalizar la extruimos  a 20mm.

Este fue el proceso para crear el diseño de la carcasa que cubre la lámpara de led y el arduino.  

![Diseno carcasa](/Imagenes/diseno_carcasa.png)
Este diseño esta disponible en la carpeta [DiseñoCarcasa](https://github.com/skgadi/LED-dimmer/tree/master/Dise%C3%B1oCarcasa).
