//definição dos pinos que cada bobina representa no arduino
#define A 6
#define B 9
#define C 11


//intervalo de delay inicial que irá decair para aumentarmos a aceleração
int intervalo = 6000;

//variável responsável por armazenar o valor que decrementaremos de nosso delay
int decremento = 15;

//variáveis que armazenam os tempo em microssegundos para o delay.
const int DELAY_MINIMO = 450;
const int DELAY_ACEL_MAXIMA = 1200;
const int DELAY_MARCO_UM = 4500;
const int DELAY_MARCO_DOIS = 3200;
const int DELAY_MARCO_TRES = 2200;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);  //apaga o LED L
}

void loop() {
  //chamada da ativação das bobinas
  pulso(1);
  pulso(2);
  pulso(3);
  pulso(4);
  pulso(5);
  pulso(6);
  //enquanto o intervalo for maior que DELAY MÁXIMO o decremento é maior que 1 unidade.
  if (intervalo > DELAY_ACEL_MAXIMA) {
    //outras faixas de intervalo para ir controlando a aceleração
    if (intervalo < DELAY_MARCO_UM)
      decremento = 10;
    else if (intervalo < DELAY_MARCO_DOIS)
      decremento = 5;
    else if (intervalo < DELAY_MARCO_TRES)
      decremento = 2;
  } else
    decremento = 1;
  //tempo mínimo de delay permitido (quanto menor mais rápido o giro)
  if (intervalo > DELAY_MINIMO) {
    //subtrai de intervalo o valor atual de decremento
    intervalo -= decremento;
  } else {
    //acende o led L do arduino ao chegar na velocidade máxima permitida
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void pulso(int bobina) {

  switch (bobina) {
    case 1:  //liga a bobina A
      digitalWrite(A, HIGH);
      break;
    case 2:  //liga a bobina A e B
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      break;
    case 3:  //liga a bobina B
      digitalWrite(B, HIGH);
      break;
    case 4:  //liga a bobina B e C
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 5:  //liga a bobina C
      digitalWrite(C, HIGH);
      break;
    case 6:  //liga a bobina C e A
      digitalWrite(C, HIGH);
      digitalWrite(A, HIGH);
      break;
  }
  //tempo que a(s) bobina(s) ficam ligadas
  delayMicroseconds(intervalo);

  //desliga todas as bobinas
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  delayMicroseconds(intervalo);
}