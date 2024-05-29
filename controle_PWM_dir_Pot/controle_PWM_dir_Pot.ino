
const int pin4 = 9;
const int pin1 = 7;
const int pin2 = 8;
const int pin3 = 10;
const int POT = A5;

int valor = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(POT, INPUT);
  analogWrite(pin3, LOW);
  analogWrite(pin4, LOW);
  
}

void loop() {
  
  analogRead(POT);
  
  if(POT<512){
    analogWrite(pin3, LOW);
    analogWrite(pin4, HIGH);
    }
  else if(POT>512){
    analogWrite(pin4, LOW);
    analogWrite(pin3,HIGH);
    }else{
      analogWrite(pin3, LOW);
      analogWrite(pin4, LOW);      
      }
}
