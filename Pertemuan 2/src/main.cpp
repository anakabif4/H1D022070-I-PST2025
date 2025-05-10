#include <Arduino.h>

// Variabel
int echoPin = D1;
int trigPin = D6;
int ledPin = D3;

// 
long duration;
int distance;

void setup() {
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(6);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin,LOW);

  //Menghitung waktu sinyal diterima
  duration = pulseIn(echoPin,HIGH);

  // Menghitung jarak
  distance = duration*0.034/2;

  //Display 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");

  if (distance<=10)
  {
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  
  delay(1000);
}

