/*
Hola Mundo! - arduino. 
Enciente y apaga 1 LED

Version 1.0
Autor: Renzo Varela
*/

// La función setup es la función para configurar todos los parametros internos de Arduino. A medida que avancemos iremos viendo diferentes parametros.
// Esta funcion siempre debe exisitir
void setup() {
  pinMode(13, OUTPUT); // Esta linea de código está definiendo el pin 13 como una salida.
}

//La función loop es la funcion principal del programa de Arduino. Es una función que se repite una y otra vez hasta el infinito (o hasta que dure la bateria).
void loop() {
  digitalWrite(13, HIGH);   // Se enciende el LED (HIGH = señal de 5V)
  delay(1000);                       // se esperan 1000 milisegundos
  digitalWrite(13, LOW);    // Se apaga el LED (LOW = señal de 0V)
  delay(1000);                       // se esperan 1000 milisegundos
}
