// Caravanas SNCT 2023
// SECITEC - Prefeitura Municipal de João Pessoa
// Divisão de Manutenção e Suporte
// Programa : Acende LED

// Aqui ficam configurações de programa que devem ser rodadas apenas uma vez  
void setup()
{
  //Define a porta do led como saida
  pinMode(11, OUTPUT);
}

// Aqui vai o código que deve ser repitido em sua funcionalidade  
void loop()
{
  //Acende o led
  digitalWrite(11, HIGH);
    
  //Aguarda intervalo de tempo em milissegundos
  delay(1000);
    
  //Apaga o led
  digitalWrite(11, LOW);
    
  //Aguarda intervalo de tempo em milissegundos
  delay(1000);
}