// C++ code
//

#include "Servo.h"

Servo servo1;

int IN1 = 2;
int IN2 = 4;
int IN3 = 6;
int IN4 = 7;

long randNumber;
int es=105, di=35;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}



void setup() {
  servo1.attach(3);  
  pinMode(0, OUTPUT);
  Serial.begin(9600);
  delay(3000);

}

void loop() {

  Serial.println(0.01723 * readUltrasonicDistance(10, 11));
   if (0.1723 * readUltrasonicDistance(10, 11) < 200) {
    Serial.println("Muito Perto");
    randNumber = random(0,2);;
    //Para o motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    //Para o motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    if(randNumber ==0){
      servo1.write(di);
      }
    else{
      servo1.write(es);
      }
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(2000);
    }
   else if (0.1723 * readUltrasonicDistance(10, 11) < 300) {
    Serial.println("Perto");
    randNumber = random(0,2);
    Serial.println(randNumber);
    if(randNumber ==0){
      servo1.write(di);
      }
    else{
      servo1.write(es);
      }
    delay(5000);
    }
   else {
    Serial.println("Longe");
    servo1.write(70);
    }
   delay(1000);
}
