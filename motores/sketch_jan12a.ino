
/*Programa que permite probar Servo Motores

Desarrollo: Renzo Varela
Version: 1.0
Fecha: Enero 2023
*/

#include <Servo.h>

//DEFINICION DE LOS OBJETOS
Servo *servo[6];

void setup() {
  Serial.begin(9600);
  inicio_motores();

  //setup_fisico();
  //mov1(90,10);
  //mov2(45,5);

}

void loop() {
  //mov1(90,10);
  delay(3000);
  mov2(45,5);
}


void inicio_motores(){
  for(int i=0;i<=6;i++){
    servo[i] = new Servo();
  }
    servo[0]->attach(3);
    servo[1]->attach(5);
    servo[2]->attach(6);
    servo[3]->attach(9);
    servo[4]->attach(10);
    servo[5]->attach(11);  

  for(int i=0;i<=6;i++){
    servo[i]->write(159);
    delay(1000);
    servo[i]->write(0);
    delay(1000);
  }
}


void mov1(int grado,int vel){
 
  for(int i=0;i<=6;i++){
    for(int j=0;j<grado;j++){
      servo[i]->write(j);
      delay(vel);
    }
  }

}

void mov2(int grado,int vel){

  for(int j=0;j<=grado;j++){
    for(int i=0;i<=6;i++){
      servo[i]->write(0+j);
    }
  delay(vel);
  }

}

