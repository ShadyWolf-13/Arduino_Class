
const int pin4 = 9;
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
  
  if(POT>0){
    analogWrite(pin3, LOW);

    valor = analogRead(POT);
    valor = map(valor,0,1023,0,255);
    analogWrite(pin4,valor);
    }
else{
      analogWrite(pin3, LOW);
      analogWrite(pin4, LOW);      
      }
}
