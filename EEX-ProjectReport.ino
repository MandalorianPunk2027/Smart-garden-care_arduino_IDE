#include <WiFi.h>
#include <WiFiClient.h>

#define motorA_pin1 21  // 1st pin //motor A
#define motorA_pin2 19
#define motorB_pin1 5  // 1st pin //motor B
#define motorB_pin2 18
#define sensor1 34
#define sensor2 35
#define valve1 23
#define valve2 4
int threshold = 500;

char ssid[] = "Xiaomi 11 Lite 5G NE";   
char pass[] = "blablabla"; 

void setup() {
  pinMode(motorA_pin1, OUTPUT);
  pinMode(motorA_pin2, OUTPUT);
  pinMode(motorB_pin1, OUTPUT);
  pinMode(motorB_pin2, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(valve1, OUTPUT);
  pinMode(valve2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(motorB_pin1, LOW);
  digitalWrite(motorB_pin2, LOW);
  digitalWrite(motorA_pin1, LOW);
  digitalWrite(motorA_pin2, LOW);
  digitalWrite(valve1, LOW);
  digitalWrite(valve2, LOW);
}

void runB() {
  digitalWrite(motorB_pin1, HIGH);
  digitalWrite(motorB_pin2, LOW);
}

void runA(){
  digitalWrite(motorA_pin1, HIGH);
  digitalWrite(motorA_pin2, LOW);
}

void stop() {
  digitalWrite(motorA_pin1, LOW);
  digitalWrite(motorA_pin2, LOW);
  digitalWrite(motorB_pin1, LOW);
  digitalWrite(motorB_pin2, LOW);
}

void loop() {
  int moisture_value1 = analogRead(sensor1);
  int moisture_value2 = analogRead(sensor2);

  if(moisture_value1 < threshold) //plant1
  {
    Serial.println("water the plant");
    digitalWrite(valve1, HIGH); //open valve
    runA();
    delay(2000);
    digitalWrite(valve1, LOW);
    stop();
  }
  if(moisture_value2 < threshold) //plant2
  {
    Serial.println("water the plant");
    digitalWrite(valve2, HIGH);// open valve
    runA();
    delay(2000);
    digitalWrite(valve2, LOW);
    stop();
  }
  delay(3000);
  Serial.println(moisture_value1);
  Serial.println(moisture_value2);
  delay(3000);
}