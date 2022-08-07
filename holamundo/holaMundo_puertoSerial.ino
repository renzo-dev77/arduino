/*
HolaMundo!
Puerto Serial

Version 1.0
Autor: Renzo Varela
*/

// La función setup es la función para configurar todos los parametros internos de Arduino. A medida que avancemos iremos viendo diferentes parametros.
// Esta funcion siempre debe exisitir
void setup() {
  Serial.begin(9600);   // El puerto serial es un puerto que tiene Arduino para comunicarse con el computador. Esta función da inicio o activa el puerto serial
}

//La función loop es la funcion principal del programa de Arduino. Es una función que se repite una y otra vez hasta el infinito (o hasta que dure la bateria).
void loop() {
  Serial.println("Hola Mundo"); // println es una función que permite escribir por el puerto serial todo lo que este dentro del parentesis.
  delay(1000);                  // Se esperan 1000 milisegundos
}
