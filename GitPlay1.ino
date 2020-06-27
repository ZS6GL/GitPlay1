//Constants
const int pinCount = 12;
const int rowCount = 14;

//Array to hold Pins
int ledPins[pinCount] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

//Array to hold Pattern1    int matrix[rows][leds];
int matrix[rowCount][pinCount] = {
  {1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,0,0,0,1,0,1,0,0,1,0},
  {0,1,0,0,1,0,0,1,0,0,1,0},
  {0,0,1,0,0,0,0,1,0,0,1,0},
  {0,0,0,1,0,0,0,1,0,1,0,0},
  {0,0,0,0,1,0,0,1,0,1,0,0},
  {0,0,0,0,0,1,0,0,0,1,0,0},
  {0,0,1,0,0,0,1,0,1,0,0,1},
  {0,0,0,1,0,1,0,1,0,1,0,0},
  {0,1,0,0,1,0,0,1,1,0,1,0},
  {0,0,0,1,0,0,0,1,0,1,0,0},
  {0,0,0,0,1,0,1,0,0,0,1,0},
  {0,0,0,1,0,1,1,0,0,0,0,1},
  {0,0,0,0,0,0,1,0,1,0,0,0},
};

//Array to hold Pattern2    int matrix[rows][leds];
int matrix2[rowCount][pinCount] = {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0,1,0,0,0},
  {0,0,0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,0,1,0,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
};

//Array to hold Pattern3    int matrix[rows][leds];
int matrix3[rowCount][pinCount] = {
  {1,0,0,0,0,0,1,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0},
  {0,0,1,0,1,0,0,0,0,0,1,0},
  {0,1,0,0,0,1,0,0,0,1,0,0},
  {1,0,0,0,0,0,1,0,1,0,0,0},
  {0,1,0,0,0,0,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0,0,0,1,0},
  {0,0,0,0,0,1,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0,1,0,0,0},
  {0,0,0,0,0,0,0,1,0,0,0,0},
};

//Array to hold Pattern4    int matrix[rows][leds];
int matrix4[rowCount][pinCount] = {
  {1,0,0,0,0,0,1,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0},
  {0,0,1,0,1,0,0,0,0,0,1,0},
  {0,1,0,0,0,1,0,0,0,1,0,0},
  {1,0,0,0,0,0,1,0,1,0,0,0},
  {0,1,0,0,0,0,0,1,0,0,0,0},
  {0,0,1,0,1,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0,0,0,1,0},
  {0,0,0,0,0,1,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0,1,0,0,0},
  {0,0,0,0,0,0,0,1,0,0,0,0},
};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < pinCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pattern;
  pattern = random(0,4);

  switch (pattern) {
    case 0:
    displayMatrix(matrix);
    break;
    case 1:
    displayMatrix(matrix2);
    break;
    case 2:
    displayMatrix(matrix3);
    break;
    case 3:
    displayMatrix(matrix4);
    break;
  }
  
  delay(500);
}

void setLed(int ledPin, int value) {
  digitalWrite(ledPin, value);
  //Serial.print(ledPin); Serial.print(" "); Serial.println((value == 1) ? "X" : "0");
}

void displayMatrix(int m [][pinCount]) {
  for (int iRow = 0; iRow < rowCount; iRow++) {
    for (int iLed = 0; iLed < pinCount; iLed++) {
      setLed(ledPins[iLed], m[iRow][iLed]);
      Serial.print(ledPins[iLed]); Serial.print(" "); Serial.println(matrix[iRow][iLed]);
     }
     delay(100);
     Serial.println("------");
  }
}

void loop1() {
  for (int iRow = rowCount-1; iRow >= 0; iRow--) {  // iRow = iRow - 1;
    for (int iLed = 0; iLed < pinCount; iLed++) {
      //setLed(ledPins[iLed], matrix[iRow][iLed]);
      digitalWrite(ledPins[iLed], matrix[iRow][iLed]);
      Serial.print(ledPins[iLed]); Serial.print(" "); Serial.println(matrix[iRow][iLed]);
    }
    Serial.println("------");
    delay(500);  //Delay after each ROW
  }

  delay(1000);
}
