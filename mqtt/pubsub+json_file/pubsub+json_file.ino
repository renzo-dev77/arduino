/* 
 *  PUBSUB - AWS
 *  
 *  Funcionamiento: Tarejeta ESP32 se conecta a AWS IoT core por medio de MQTT 
 *                  para publicar mensajes por un tópico y recibir 
 *                  mensajes por otro tópico
 *  
 *  Basado en el ejemplo de Anthony Elder
 *  https://github.com/HarringayMakerSpace/awsiot/blob/master/Esp32AWSIoTExample/Esp32AWSIoTExample.ino
 *  
 * Autor: Renzo Varela 
 * Fecha: 18-04-2021
 * License: --
 */


#include <WiFiClientSecure.h>
#include <PubSubClient.h> // install with Library Manager, I used v2.6.0
#include <ArduinoJson.h>
#include "certificados.h"


// CREDENCIALES WIFI Y AWS

WiFiClientSecure wiFiClient;
void msgReceived(char* topic, byte* payload, unsigned int len);
PubSubClient pubSubClient(awsEndpoint, 8883, msgReceived, wiFiClient); 

DynamicJsonBuffer jsonPubBuff;  // Buffer para los JSON enviados
DynamicJsonBuffer jsonSubBuff;  // Buffer para JSON recibido


//NOMBRE DE LOS TOPICOS
#define IN_TOPIC "topico01"
#define OUT_TOPIC_1 "topico01"


void setup() {
  
  Serial.begin(115200); delay(50); Serial.println();
  Serial.println("Basic pub-sub firmware v2.2");
  Serial.print("IN TOPIC: ");
  Serial.println(IN_TOPIC);
  //Serial.print("OUT TOPIC: ");
  //Serial.println(OUT_TOPIC);
  Serial.print("Connecting to "); Serial.print(ssid);
  WiFi.begin(ssid, password);
  WiFi.waitForConnectResult();
  Serial.print(", WiFi connected, IP address: "); Serial.println(WiFi.localIP());

  wiFiClient.setCACert(rootCA);
  wiFiClient.setCertificate(certificate_pem_crt);
  wiFiClient.setPrivateKey(private_pem_key);

  
}

unsigned long lastPublish;
long msgCount;

// Definicion del payload (JSON) que se va a enviar en cada topico
JsonObject& payload1 = jsonPubBuff.createObject();

void loop() {

  //CHECKEA CONEXION MQTT CON AWS
  pubSubCheckConnect();
  
  if (millis() - lastPublish > 120000) {

    input();

    lastPublish = millis();
    }

  
}

  
void input(){
/*
 ********************************************************
 ********************************************************
ESCRIBIR ACA SU CODIGO PARA OBTENER VALORES DE LOS INPUTS
*********************************************************
*********************************************************
*/
  msgCount++;
  //CONSTRUYE NUEVO JSON
  payload1["estado"]= 0;
  payload1["PWM"]= 511;
  payload1["valor01"]=msgCount;
  payload1["valor02"]=msgCount;
  payload1["rgb_red"]=msgCount;
  payload1["rgb_green"]=msgCount;
  payload1["rgb_blue"]=msgCount;
  
  // CAMBIA EL FORMATO DEL PAYLOAD
  String sPayload;
  char* cPayload;    
  sPayload = "";
  payload1.printTo(sPayload);
  cPayload = &sPayload[0u]; 
  
  //PUBLISH TOPIC        
  //String msg = String("{\nHello from ESP8266: \n}\n"); //+ ++msgCount;
  boolean rc = pubSubClient.publish(OUT_TOPIC_1, cPayload);
  Serial.print("Published, rc="); Serial.print( (rc ? "OK: " : "FAILED: ") );
  Serial.println(cPayload);
  }

void output(int estado, int pwm, int valor1, int valor2, int rojo, int verde, int azul){
  /*
  ********************************************************
  ********************************************************
  ESCRIBIR ACA SU CODIGO PARA OBTENER VALORES DE LOS INPUTS
  *********************************************************
  *********************************************************
    //POR EJEMPLO:
    if (estado==1){
      Serial.println("BOTON PRESIONADO DESDE INTERNET");
      }
    else{
      Serial.println("nada ha pasado aun");
      }
      */
  }

void msgReceived(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on "); Serial.print(topic); Serial.print(": ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  
  // DEFINICION DEL JSON QUE SE RECIBE
  JsonObject& jsonReceived = jsonSubBuff.parseObject(payload);

  // ASIGNA VARIABLES LOCALES A LOS CAMPOS DEL JSON RECIBIDO
  int estado = jsonReceived["estado"];
  int pwm = jsonReceived["pwm"];
  int val01 = jsonReceived["val01"];
  int val02 = jsonReceived["val02"];
  int rgb_rojo = jsonReceived["rgb_red"];
  int rgb_verde = jsonReceived["rgb_green"];
  int rgb_azul = jsonReceived["rgb_blue"];

  //FUNCION PARA PROGRAMAR LAS SALIDAS
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  output(estado,pwm,val01,val02,rgb_rojo,rgb_verde,rgb_azul);
}

//CONECION CON EL SERVIDOR (AWS)
void pubSubCheckConnect() {
  if ( ! pubSubClient.connected()) {
    Serial.print("PubSubClient connecting to: "); Serial.print(awsEndpoint);
    while ( ! pubSubClient.connected()) {
      Serial.print(".");
      pubSubClient.connect(DEVICENAME);
      delay(1000);
    }
    Serial.println(" connected");
    pubSubClient.subscribe(IN_TOPIC);
  }
  pubSubClient.loop();
}
