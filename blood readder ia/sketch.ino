// Definição do pino do sensor de proximidade
const int sensorPin = 2;

// Variáveis para armazenar o estado atual e anterior do sensor
int currentState = LOW;
int previousState = LOW;

// Variável para contar o número de pessoas
int peopleCount = 0;

void setup() {
  // Inicialização do pino do sensor como entrada
  pinMode(sensorPin, INPUT);
  
  // Inicialização da porta serial
  Serial.begin(9600);
}

void loop() {
  // Leitura do estado atual do sensor
  currentState = digitalRead(sensorPin);
  
  // Verifica se houve uma mudança de estado (de LOW para HIGH)
  if (currentState == HIGH && previousState == LOW) {
    // Incrementa o contador de pessoas
    peopleCount++;
    
    // Imprime o número atual de pessoas detectadas
    Serial.print("Pessoas detectadas: ");
    Serial.println(peopleCount);
    
    // Aguarda um curto período de tempo para evitar contagens múltiplas
    delay(1000);
  }
  
  // Atualiza o estado anterior do sensor
  previousState = currentState;
}

