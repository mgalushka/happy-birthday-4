/**
 * My son Kostya has his 4th birthday on 17-Jan.
 *
 * I decided to make a small present to him.
 * 
 * To make electronic Pi with 4 diodes lightning in some different patterns
 */

// pins to control candles
static int ledPins[] = {
  2, 3, 4, 5};

static int buttonPin = 6;
int buttonValue = 0;
boolean animation = false;

int LEDCOUNT = 4;

void setup(){
  for(int i = 0; i <= 3; i++){
    pinMode(ledPins[i], OUTPUT);  // declare LEDs as output
  }
  pinMode(buttonPin, INPUT);      // declare pushbutton as input
}

void loop(){
  int currentButtonValue = digitalRead(buttonPin);  // read input value
  if(currentButtonValue != buttonValue){
    // new value
    if (buttonValue == HIGH) {  
      // change animation status
      animation = !animation;
    }
  }

  if(animation){
    seqOne();
    seqTwo();
    seqThree();
    seqFour();
    seqFive();
    turnAll(LOW);
    delay(2000);
  }
}

void seqOne() {
  int seqOne[6] = {
    0, 0, 0, 0, 0, 0      };
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < LEDCOUNT; i++) {
      seqOne[i] = ~seqOne[i];
      digitalWrite(ledPins[i], seqOne[i]);
      delay(50);
    }
  }
}

void seqTwo() {
  int seqTwo[6] = {
    0, 1, 0, 1, 0, 1      };
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < LEDCOUNT; i++) {
      seqTwo[i] = ~seqTwo[i];
      digitalWrite(ledPins[i], seqTwo[i]);
      delay(100);
    }
  }
}

void seqThree() {
  int seqThree[6] = {
    0, 0, 0, 0, 0, 0      };
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < LEDCOUNT; i++) {
      seqThree[i] = ~seqThree[i];
      digitalWrite(ledPins[i], seqThree[i]);
      delay(100);
    }
    for (int i = (LEDCOUNT-1); i >= 0; i--) {
      seqThree[i] = ~seqThree[i];
      digitalWrite(ledPins[i], seqThree[i]);
      delay(50);
    }
  }
}

void seqFour() {
  int seqFour[6] = {
    0, 0, 0, 0, 0, 0      };
  for (int k = 0; k < 5; k++) {
    for (int j = 0; j < 240; j++) {
      for (int i = 0; i < LEDCOUNT; i++) {
        analogWrite(ledPins[i], j);
        seqFour[i] = j;
      }
      delay(2);
    }

    for (int j = 192; j >= 0; j--) {
      for (int i = 0; i < LEDCOUNT; i++) {
        analogWrite(ledPins[i], j);
        seqFour[i] = j;
      }
      delay(5);
    }
  }
}

void seqFive() {
  int seqFive[6] = {
    1, 1, 1, 0, 0, 0      };
  for (int j = 0; j < 50; j++) {
    for (int i = 0; i < LEDCOUNT; i++) {
      seqFive[i] = !seqFive[i];
      digitalWrite(ledPins[i], seqFive[i]);
    }
    delay((1500/(j+1)));
  }
}

void turnAll(int value) {
  for (int i = 0; i < LEDCOUNT; i++) {
    digitalWrite(ledPins[i], value);
  }
}









