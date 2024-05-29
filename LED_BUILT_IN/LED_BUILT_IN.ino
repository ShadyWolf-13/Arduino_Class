// Caravanas SNCT 2023
// SECITEC - Prefeitura Municipal de João Pessoa
// Divisão de Manutenção e Suporte
// Programa: Teste LED_BUILT_IN

void setup() {
  //Inicializar LED embutido como saída:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Acende o LED (HIGH é o nível da Voltagem alta ou ligado)
  delay(500); // Espera de 1s
  digitalWrite(LED_BUILTIN, LOW); // Desliga o LED (LOW é para baixa voltagem ou desligado)
  delay(500); // Espera de 1s
}


