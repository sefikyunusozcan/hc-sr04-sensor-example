//Ultrasonic library
#include <Ultrasonic.h>
#include "Ultrasonic.h"

Ultrasonic ultrasonic(6,7);

//led pins
const int ledgreen = 13;
const int ledyellow = 12;
const int ledred = 11;

//start distance and read time
long microsec = 0;
float distanceCM = 0;

void setup () {
Serial.begin(9600); 

pinMode(ledgreen,OUTPUT); 
pinMode(ledyellow,OUTPUT); 
pinMode(ledred,OUTPUT); 
}

void loop () {
microsec = ultrasonic.timing(); 
distanceCM = ultrasonic.convert(microsec, Ultrasonic::CM); 

ledDistance();

Serial.print(distanceCM);
Serial.println(" cm");
delay(600);
}

void ledDistance () {

digitalWrite(ledgreen,LOW);
digitalWrite(ledyellow,LOW);
digitalWrite(ledred,LOW);

//if distance bigger than 20 cm, green led will blink
if (distanceCM > 20) {
digitalWrite(ledgreen,HIGH);
}

//if distance between 20 cm - 10 cm, yellow led will blink
if (distanceCM <=20 and distanceCM >= 10) {
digitalWrite(ledyellow,HIGH);
}

//if distance less than 10 cm, red led will blink
if (distanceCM < 10) {
digitalWrite(ledred,HIGH);
}
}
