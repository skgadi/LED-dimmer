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