
// La rutina stup se ejecuta una vez cada vez que se apreta el boton reset:
void setup() {
  Serial.begin(9600); // se inicia la comunicacion serial entre el uC y el computador.
}

// La rutina loop se repite una y otra vez hasta el infinito
void loop() {
  int sensorValue = analogRead(A0); // lee la entrada analoga en el pin A0 de un Arduino UNO
  Serial.println(sensorValue);  // imprime por el puerto serial el valor digital
  delay(500);        // delay en milisengundos. el programa se deteiene por 500ms
  
  
}
