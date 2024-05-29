// C++ code
//
int MedidaUmidade = 0;

int D4 = 0;

int PinoSensorA = 0;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  MedidaUmidade = analogRead(A1);
  if (MedidaUmidade >= 400) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
