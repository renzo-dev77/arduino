

// cada vez que escriba "pushButton" significa el numero 2
int pushButton = 2;

// La rutina stup se ejecuta una vez cada vez que se apreta el boton reset:
void setup() {
  Serial.begin(9600);   // se inicia la comunicacion serial entre el uC y el computador.
  pinMode(pushButton, INPUT);    // definir el pin "pushButton" como entrada
}

// La rutina loop se repite una y otra vez hasta el infinito
void loop() {
  int buttonState = digitalRead(pushButton);    // lee el pin
  Serial.println(buttonState); // imprime el valor del pin por el puerto serial
  delay(500);        // delay en milisengundos. el programa se deteiene por 500ms
}
