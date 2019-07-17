#include <ESP8266WiFi.h> 
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "new_index.h"
//IPAddress ip(192,168,1,8); // Creating static IP
//IPAddress gateway(192,168,1,1);
//IPAddress subnet(255,255,255,0);
ESP8266WebServer server(80);
#ifndef STASSID
#define STASSID "vivo 1718" // Your SSID
#define STAPSK  "satusamhu" // Your PSK
#endif
const char* ssid = STASSID;
const char* password = STAPSK;
uint8_t switch_1 = 16;
uint8_t switch_2 = 5;
uint8_t sensor_input = 4; //echo pin
uint8_t sensor_output = 2; // trig pin
int distances;
double durations;
void setup() 
{
  pinMode(switch_1, OUTPUT);
  pinMode(switch_2, OUTPUT);
  pinMode(sensor_input,INPUT);
  pinMode(sensor_output,OUTPUT);
  //WiFi.config(ip,gateway,subnet); // static
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);  
  }
  Serial.println("");
  Serial.print("Go The This IP: http://");
  Serial.println(WiFi.localIP());
  server.on("/",[](){server.send_P(200,"text/html", MyWebPage);});
  server.on("/switch1state",getSwitch1State);
  server.on("/switch2state",getSwitch2State);
  server.on("/readSensor1", Sensor1Data);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() 
{
  server.handleClient();
  delay(5);
}
void getSwitch1State()
{
  toggleSwitch1();
  String switch1_state = digitalRead(switch_1) ? "OFF" : "ON";
  server.send(200,"text/html", switch1_state);
}
void getSwitch2State()
{
  toggleSwitch2();
  String switch2_state = digitalRead(switch_2) ? "ON" : "OFF";
  server.send(200,"text/html", switch2_state);
}
void toggleSwitch1()
{
  digitalWrite(switch_1,!digitalRead(switch_1));
}

void toggleSwitch2()
{
  digitalWrite(switch_2,!digitalRead(switch_2));
}

void Sensor1Data() {
 digitalWrite(sensor_output,LOW);
 delayMicroseconds(2);
 digitalWrite(sensor_output,HIGH);
 delayMicroseconds(10);
 digitalWrite(sensor_output,LOW);
 durations = pulseIn(sensor_input,HIGH);
 distances = 0.0343 * durations/2;
 String sensor1Value = String(distances);
 server.send(200, "text/html", sensor1Value); //Send ADC value only to client ajax request
}
