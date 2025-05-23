  #include "USB.h"
 #include "USBHIDKeyboard.h"

 USBHIDKeyboard Keyboard;
 const int buttonPin_1 = 11;
 const int buttonPin_2 = 13;

  const int ledPin = 12;
  const int ledPin2 = 15;
  const int ledPin3 = 10;
  const int ledPin4 = 4;

  const int potPin = 2;
  int ButPin = 1;
  int ButtonPin = 9;



  int ms = 250;
  bool ledState = 0;
  bool buttonState_1 = 0;
  bool buttonState_2 = 0;
  bool prevButtonState_1 = 0;
  bool prevButtonState_2 = 0;


 

void setup() {
  // put your setup code here, to run once:
  // reads button state 1 and 2
  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ButtonPin,INPUT);
  Serial.begin(115200);
  USB.begin();
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState_1 = !digitalRead(buttonPin_1);
  buttonState_2 = !digitalRead(buttonPin_2);

  if (buttonState_1 && !prevButtonState_1)
  {
    Keyboard.write('A'); 
  }
  prevButtonState_1 = !digitalRead(buttonPin_1);

  if (buttonState_2 && !prevButtonState_2) 
  {
    Keyboard.write('Z'); 
  }
  prevButtonState_2 = !digitalRead(buttonPin_2);

  delay(5);
  digitalWrite(ledPin, HIGH);
  delay(ms);
  digitalWrite(ledPin, LOW);
  delay(ms);

  digitalWrite(ledPin2, LOW);
  delay(ms);
  digitalWrite(ledPin2, HIGH);
  delay(ms);

  int potValue = analogRead(potPin);
  int tuning = map(potValue, 0, 1023, 100, 255);
  analogWrite(ledPin3, tuning);
  Serial.println(tuning);

  if(digitalRead(ButtonPin) == LOW){
    digitalWrite(ledPin4, HIGH);
  }
  else{
    digitalWrite(ledPin2, HIGH); //button is pressed
  }

}