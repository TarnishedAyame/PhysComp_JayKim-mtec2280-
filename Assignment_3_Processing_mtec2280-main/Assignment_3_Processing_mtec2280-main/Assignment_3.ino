assignment 3

const int potPin = 2

int lastTime = 0;
int currentTime = 0;
int timerInterval = 20;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 analogReadResolution(4);
}

void loop() {
  // put your main code here, to run repeatedly:

   currentTime = millis(); 
  if (currentTime - lastTime >= timerInterval)
  {
    lastTime = currentTime; 
    adcRead = analogRead(potPin);
}