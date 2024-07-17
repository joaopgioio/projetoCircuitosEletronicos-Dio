const int sensorPin = A0; // Pin do sensor de temperatura
const int motorPin = 6;   // Pin do motor
const int ledPin = 7;     // Pin do LED
const int buzinaPin = 8;  // Pin do buzzer

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzinaPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  // Aqui convertemos a leitura analógica para tensão
  float voltage = sensorValue * (5.0 / 1023.0);

  // Aqui convertemos a tensão para temperatura em graus Celsius
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC >= 30.0) {
    digitalWrite(motorPin, HIGH); // Liga o motor
  } else {
    digitalWrite(motorPin, LOW); // Desliga o motor
  }

  if (temperatureC > 50.0) {
    digitalWrite(ledPin, HIGH);  // Liga o LED
    digitalWrite(buzinaPin, HIGH); // Liga a buzina
  } else {
    digitalWrite(ledPin, LOW);  // Desliga o LED
    digitalWrite(buzinaPin, LOW); // Desliga a buzina
  }

  delay(1000); // Aguarda 1 segundo
}
