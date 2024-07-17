# Projeto de Controle de Temperatura com Arduino

## Descrição do Projeto

Este projeto simula uma estufa de hortaliças controlada por um Arduino. O sistema monitora a temperatura ambiente usando um sensor de temperatura TMP36 e realiza as seguintes ações:

1. **Leitura da Temperatura**:
   - O Arduino lê a temperatura ambiente através do sensor TMP36.

2. **Controle do Ventilador**:
   - Se a temperatura for igual ou maior que 30°C, um motor de ventilador é acionado para resfriar a estufa.

3. **Alarme de Emergência**:
   - Se a temperatura ultrapassar 50°C, um LED vermelho acende e uma buzina é ativada para indicar uma situação de emergência.

## Componentes Utilizados

- Arduino Uno
- Sensor de Temperatura TMP36
- Motor de Ventilador
- LED Vermelho
- Buzzer (Buzina)
- Resistores (220 ohms para o LED)
- Protoboard e Jumpers

## Esquema de Conexão

### Sensor TMP36
- **Vcc** -> 5V (Arduino)
- **GND** -> GND (Arduino)
- **Vout** -> A0 (Arduino)

### Motor de Ventilador
- Um terminal -> D6 (Arduino) (através de um transistor, se necessário)
- Outro terminal -> GND (Arduino)

### LED Vermelho
- **Anodo (perna longa)** -> D7 (Arduino) (através de um resistor de 220 ohms)
- **Catodo (perna curta)** -> GND (Arduino)

### Buzzer
- **Positivo** -> D8 (Arduino)
- **Negativo** -> GND (Arduino)

## Código Fonte

```cpp
// Definição dos pinos
const int sensorPin = A0; // Pin do sensor de temperatura TMP36
const int motorPin = 6;   // Pin do motor de ventilador
const int ledPin = 7;     // Pin do LED vermelho
const int buzzerPin = 8;  // Pin do buzzer

void setup() {
  Serial.begin(9600);      // Inicializa a comunicação serial a 9600 bps
  pinMode(motorPin, OUTPUT); // Define o pin do motor como saída
  pinMode(ledPin, OUTPUT);   // Define o pin do LED como saída
  pinMode(buzzerPin, OUTPUT);// Define o pin do buzzer como saída
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Lê o valor analógico do sensor de temperatura

  // Converte a leitura analógica para tensão
  float voltage = sensorValue * (5.0 / 1023.0);

  // Converte a tensão para temperatura em graus Celsius
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Verifica se a temperatura é maior ou igual a 30°C
  if (temperatureC >= 30.0) {
    digitalWrite(motorPin, HIGH); // Liga o motor do ventilador
  } else {
    digitalWrite(motorPin, LOW); // Desliga o motor do ventilador
  }

  // Verifica se a temperatura ultrapassa 50°C
  if (temperatureC > 50.0) {
    digitalWrite(ledPin, HIGH);  // Liga o LED vermelho
    digitalWrite(buzzerPin, HIGH); // Liga o buzzer
  } else {
    digitalWrite(ledPin, LOW);  // Desliga o LED vermelho
    digitalWrite(buzzerPin, LOW); // Desliga o buzzer
  }

  delay(1000); // Aguarda 1 segundo antes de fazer a próxima leitura
}



Funcionamento do Código
Setup:

Inicializa a comunicação serial.
Define os pinos do motor, LED e buzzer como saídas.
Loop:

Lê o valor analógico do sensor TMP36.
Converte o valor lido em tensão.
Converte a tensão em temperatura em graus Celsius.
Imprime a temperatura no monitor serial.
Liga o motor do ventilador se a temperatura for maior ou igual a 30°C.
Liga o LED vermelho e o buzzer se a temperatura ultrapassar 50°C.
Aguarda 1 segundo antes de repetir o processo.
Considerações Finais
Este projeto é uma simulação simples de um sistema de controle de temperatura para uma estufa de hortaliças. Ele pode ser expandido para incluir mais sensores, controle de umidade, iluminação automática, entre outros recursos. O uso do TinkerCad facilita a simulação e a visualização do circuito antes da montagem física.



Este documento detalha o projeto, componentes, conexões, e explica o código usado para controlar o sistema de temperatura com Arduino.
