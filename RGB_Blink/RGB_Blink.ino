/* Project 1: RGB Blinky
   Uses a single RGB LED to cycle through three colors.
*/
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  redGreenBlue();
  white();
  redBlue();
  redGreen();
  blueGreen();
}

void white() {
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  // turns on green
  digitalWrite(11, HIGH);  // turns on blue
  delay(3000);             // waits for 1 second
}

void redBlue() {
  digitalWrite(9, LOW);    // turns off green
  digitalWrite(10, HIGH);  // turns on blue
  digitalWrite(11, HIGH);  // turns on red
  delay(3000);             // waits for 1 second
}

void blueGreen() {
  digitalWrite(9, HIGH);    // turns on green
  digitalWrite(10, HIGH);  // turns on blue
  digitalWrite(11, LOW);  // turns off red
  delay(3000);             // waits for 1 second
}

void redGreen() {
  digitalWrite(9, HIGH);   // turns on green
  digitalWrite(10, LOW);  // turns off blue
  digitalWrite(11, HIGH);  // turns on red
  delay(3000);             // waits for 1 second
}

void redGreenBlue() {
  digitalWrite(9, HIGH);  // turns on green
  digitalWrite(11, LOW);  // turns off red
  delay(1000);
  digitalWrite(10, HIGH);  // turns on blue
  digitalWrite(9, LOW);    // turns off green
  delay(1000);             // waits for 1 second
  digitalWrite(11, HIGH);  // turns on red
  digitalWrite(10, LOW);   // turns off blue
  delay(1000);             // waits for 1 second
}
 void Christmas() {
  digitalWrite(9, HIGH);  // turns on green
  delay(1000); 
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns off red
  delay(1000); 
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);    // turns off green
  delay(1000);             // waits for 1 second
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns on red
  delay(1000);           
  digitalWrite(9, HIGH);  // turns on green
  delay(1000); 
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns off red
  delay(1000); 
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);    // turns off green
  delay(1000);             // waits for 1 second
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns on red
  delay(1000); 
  digitalWrite(9, HIGH);  // turns on green
  delay(1000); 
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns off red
  delay(1000); 
  digitalWrite(11, LOW);
  digitalWrite(9, HIGH);    // turns off green
  delay(1000);             // waits for 1 second
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);  // turns on red
  delay(1000);                       
}
  

