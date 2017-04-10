int SensorA = A0;
int SensorB = A1;
int SensorC = A2;
int SensorD = A3;
int SensorE = A4;

const int L_Top = 9;
const int L_Slise = 10;
const int R_Top = 6;
const int R_Slise = 5;

const int kp = 70;
int LMP;
int RMP;


void setup() {
  pinMode(L_Top, OUTPUT); //motorPin
  pinMode(L_Slise, OUTPUT); //motorPin
  pinMode(R_Top, OUTPUT); //motorPin
  pinMode(R_Slise, OUTPUT); //motorPin
  pinMode(SensorA, INPUT); //sensorPin
  pinMode(SensorB, INPUT); //sensorPin
  pinMode(SensorC, INPUT); //sensorPin
  pinMode(SensorD, INPUT); //sensorPin
  pinMode(SensorE, INPUT); //sensorPin
}

void loop() {
  int n = 0;
  int sokudo = 0;
  
  if (analogRead(SensorA) < 100) {
    sokudo += 100;
    n += 1;
  }
  if (analogRead(SensorB) < 100) {
    sokudo += 50;
    n += 1;
  }
  if (analogRead(SensorC) < 100) {
    sokudo += 0;
    n += 1;
  }
  if (analogRead(SensorD) < 100) {
    sokudo -= 50;
    n += 1;
  }
  if (analogRead(SensorE) < 100) {
    sokudo -= 100;
    n += 1;
  }

  if (n == 0) {
    LMP = 40;
    RMP = 40;
  } else {
    LMP = 40 - sokudo;
    RMP = 40 + sokudo;
  }

  driveMotor(LMP, RMP);
}


//don't touch! this area.
void driveMotor(int left, int right) {
  if (left > 255) {
    left = 255;
  } else if (left < -255) {
    left = -255;
  }
  if (right > 255) {
    right = 255;
  } else if (right < -255) {
    right = -255;
  }
  if (left > 0) {
    analogWrite(L_Top, left);
    analogWrite(L_Slise, 0);
  } else if (left < 0) {
    left = abs(left);
    analogWrite(L_Top, 0);
    analogWrite(L_Slise, left);
  } else {
    digitalWrite(L_Top, HIGH);
    digitalWrite(L_Slise, HIGH);
  }
  if (right > 0) {
    analogWrite(R_Top, right);
    analogWrite(R_Slise, 0);
  } else if (right < 0) {
    right = abs(right);
    analogWrite(R_Top, 0);
    analogWrite(R_Slise, right);
  } else {
    digitalWrite(R_Top, HIGH);
    digitalWrite(R_Slise, HIGH);
  }
}
