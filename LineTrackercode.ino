#define IN1 12
#define IN2 14
#define IN3 2
#define IN4 4
#define ENA 16
#define ENB 17
#define IR_SENSOR_RIGHT 32
#define IR_SENSOR_LEFT 33

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  bool rightSensor = digitalRead(IR_SENSOR_RIGHT);
  bool leftSensor = digitalRead(IR_SENSOR_LEFT);

  if (!rightSensor && !leftSensor) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (!rightSensor && leftSensor) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (rightSensor && !leftSensor) {
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }

  //I would like to remind everyone that this thing here is the IR sensor delay frequency thingy in case someone gets confused (like I did). (◕‿◕✿)
  delay(1); 
}