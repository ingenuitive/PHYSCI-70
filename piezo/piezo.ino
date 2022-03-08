const int sensor = A0;     
const int A1A = 3;
const int A1B = 4;

int sensorReading = 0;

void setup() {
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
  Serial.begin(9600);
}

void loop() {
  sensorReading = analogRead(sensor);
  
  if (sensorReading >= 25) {
    digitalWrite(A1A, HIGH);
    Serial.println(sensorReading);
    delay(3000);
    digitalWrite(A1A, LOW);
    delay(3000);
    digitalWrite(A1B, HIGH);
    delay(3000);
    digitalWrite(A1B, LOW);
  }
}
