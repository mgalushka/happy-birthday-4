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
int animationStatus = 0;

void setup(){
  for(int i = 0; i <= 3; i++){
    pinMode(ledPins[i], OUTPUT);  // declare LEDs as output
  }
  pinMode(buttonPin, INPUT);      // declare pushbutton as input
}

void loop(){

}

