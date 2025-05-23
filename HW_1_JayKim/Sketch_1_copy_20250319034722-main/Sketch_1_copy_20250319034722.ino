const int ledPin = 19;
const int John = 20;
const int Sad = 40;
const int Cider = 2;
const int buttonPin = 9;




bool buttonState = 0;
bool lastButtonState = 0;
bool toggle = 0;
bool fallToggle = 0;

int ms = 500; 
int sp = 250;


void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(John, OUTPUT);
  pinMode(Sad, OUTPUT);
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(Cider, OUTPUT);

  Serial.begin(115200);



}

void loop() {

buttonState = !digitalRead(buttonPin);

digitalWrite(ledPin, HIGH);
delay(ms);
digitalWrite(ledPin, LOW);
delay(ms);
digitalWrite(John,LOW);
delay(sp);
digitalWrite(John,HIGH);
delay(sp);

if (buttonState && !lastButtonState) //Button go from low to high
{
  toggle = !toggle;
}

if (!buttonState && lastButtonState)
{
  fallToggle = !fallToggle;
}

lastButtonState = buttonState;

digitalWrite(Sad, toggle);

digitalWrite(Cider,HIGH);


 Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);
}