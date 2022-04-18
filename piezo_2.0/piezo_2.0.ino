const int sensor = A0;     
const int A1A = 3;
const int A1B = 4;

int sensorReading = 0;
int k = 0;         
unsigned long previousTime = 0;

long interval = 500;

void setup() {
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);
    Serial.begin(9600);

}

void loop() {
  sensorReading = analogRead(sensor);
  unsigned long currentTime = millis();
  Serial.println(k);

  if ((sensorReading >= 100 and k == 0) or ((k == 1 or k == 2) and currentTime - previousTime > interval and sensorReading >= 25)){
    k ++;
    previousTime = currentTime;
  }

  if (k == 3 and currentTime - previousTime > interval and sensorReading >= 100){
   digitalWrite(A1A, HIGH);
    k ++;
    previousTime = currentTime;
  }

  if (k == 4 and currentTime - previousTime > 1000){
   digitalWrite(A1A, LOW);
    k = 0;
  }
}
