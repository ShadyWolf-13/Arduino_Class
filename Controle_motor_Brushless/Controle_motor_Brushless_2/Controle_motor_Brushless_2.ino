//definição dos pinos que cada bobina representa no arduino
#define A    6
#define B    9 
#define C    11


//intervalo de delay inicial que irá decair para aumentarmos a aceleração
int intervalo = 500;

void setup() 
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);//apaga o LED L
}

void loop()
{
 //chamada da ativação das bobinas
 pulso(1);
 pulso(2);
 pulso(3);
 pulso(4);
 pulso(5);
 pulso(6);
 digitalWrite(LED_BUILTIN, HIGH);
} 

void pulso(int bobina) 
{

 switch(bobina)
 {
  case 1: //liga a bobina A
  digitalWrite(A,HIGH);
  break;
  case 2://liga a bobina A e B
  digitalWrite(A,HIGH); 
  digitalWrite(B,HIGH);
  break;
  case 3://liga a bobina B
  digitalWrite(B,HIGH);
  break;
  case 4://liga a bobina B e C
  digitalWrite(B,HIGH); 
  digitalWrite(C,HIGH);
  break;
  case 5://liga a bobina C
  digitalWrite(C,HIGH);
  break;
  case 6://liga a bobina C e A
  digitalWrite(C,HIGH); 
  digitalWrite(A,HIGH);
  break;
  }
//tempo que a(s) bobina(s) ficam ligadas
delayMicroseconds(intervalo); 
//desliga todas as bobinas 
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
delayMicroseconds(intervalo);
}
