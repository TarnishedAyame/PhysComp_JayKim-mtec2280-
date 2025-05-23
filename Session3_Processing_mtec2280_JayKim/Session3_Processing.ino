import processing.serial.;
Serial myPort;

float x;
float y;

float easing = 0.10;
float xOffset = 0.0; 
float yOffset = 0.0; 

int potValue = 0;

void setup() {
  size(640, 360); 
  noStroke();
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
}

void draw() { 
  background(51);
   if (myPort.available() > 0) {
    potValue = myPort.read(); 
  }

  float targetX = mouseX;
  float dx = targetX - x;
  x += dx easing;

  float targetY = mouseY;
  float dy = targetY - y;
  y += dy * easing;


  float hue = map(potValue, 0, 1023, 0, 360);
  colorMode(HSB,360,100,100);
  fill(hue, 100, 100);
  ellipse(x, y, 66, 66);
  if (mousePressed) {
    fill(235);
  } else {
    fill(150);
  }

}

/* if it doesnt run then remove
   if (myPort.available() > 0) {
    potValue = myPort.read(); 
  }
  float hue = map(potValue, 0, 1023, 0, 360);
  colorMode(HSB,360,100,100);
  fill(hue, 100, 100);
  ellipse(x, y, 66, 66);
  if (mousePressed) {
    fill(235);
  } else {
    fill(150);
  }
*/