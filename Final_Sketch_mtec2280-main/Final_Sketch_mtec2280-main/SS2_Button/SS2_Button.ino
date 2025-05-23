Assignment 2 const int ledPin = 12;
const int ledPin2 = 15;
const int ledPin3 = 10;
const int ledPin4 = 4;
const int potPin = 2;
int ButtonPin = 9;
int ms = 250;
bool ledState = 0;
void setup() {  
  // put your setup code here, to run once: 
   pinMode(ledPin, OUTPUT); 
   pinMode(ledPin2, OUTPUT);
   pinMode(ledPin3, OUTPUT); 
   pinMode(ledPin4, OUTPUT);
   pinMode(ButtonPin,INPUT); 
  Serial.begin(115200); } 
  void loop() { 
    // put your main code here, to run repeatedly: 
  digitalWrite(ledPin, HIGH); 
  delay(ms); 
  digitalWrite(ledPin, LOW); 
  delay(ms); 
  digitalWrite(ledPin2, lOW); 
  delay(ms); 
  digitalWrite(ledPin2, HIGH); 
  delay(ms); 
  int potValue = analogRead(potPin); 
  int tuning = map(potValue, 0, 1023, 100, 255); 
  analogWrite(ledPin3, tuning); 
  Serial.println(tuning); 
  if(digitalRead(ButtonPin) == LOW){
   digitalWrite(Ledpin4,HIGH); 
  } else{ 
    digitalWrite(LedPin2,HIGH);//button is pressed 
    } 
  }