const int sensor = A0;     
const int A1A = 3;
const int A1B = 4;

int sensorReading = 0;
int knocks = 0;         
unsigned long previousTime = 0;

long interval = 1000;

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

  if (currentTime % 100){
    Serial.println(knocks);
  }
  
  if (sensorReading >= 100 and knocks == 0){
    knocks ++;
    previousTime = currentTime;
  } 

  if (knocks == 1 and currentTime - previousTime > interval and sensorReading >= 25){
    knocks ++;
    previousTime = currentTime;
  }

  if (knocks == 2 and currentTime - previousTime > interval and sensorReading >= 25){
    knocks ++;
    previousTime = currentTime;
  }

  if (knocks == 3 and currentTime - previousTime > interval and sensorReading >= 25){
   digitalWrite(A1A, HIGH);
    knocks ++;
    previousTime = currentTime;
  }

  if (knocks == 4 and currentTime - previousTime > 1000){
   digitalWrite(A1A, LOW);
    knocks = 0;
  }
}
