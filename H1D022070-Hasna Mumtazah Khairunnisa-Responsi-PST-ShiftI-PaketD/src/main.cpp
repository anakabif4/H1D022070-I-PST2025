#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int echoPin = D8;
int trigPin = D6;
int ledPin1 = D0;
int ledPin2 = D3;

long duration;
int distance;

void setup() {
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);

Serial.begin(9600);

myservo.attach(D0);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(6);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("m");

  if (distance<=1500)
  {
    digitalWrite(ledPin1,HIGH);
  }
  else{
    digitalWrite(ledPin2,HIGH);
  }
  
  delay(1000);

  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}