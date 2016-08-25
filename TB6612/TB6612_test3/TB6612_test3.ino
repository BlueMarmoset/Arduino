/*
 * Test of the Adafruit TB6612 motor/stepper driver board
 * Third test - separate power & both motor A and B
 */

void setup() {

  // set motor A pins to output
  pinMode(0, OUTPUT);
  pinMode(3, OUTPUT);

  // set motor B pins to output
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // set BOTH motors to a lower speed
  analogWrite(4, 100); 

  // run motor A forward
  digitalWrite(0, HIGH);
  digitalWrite(3, LOW);
  delay(500);
  
  // turn off motor A
  digitalWrite(0, LOW);
  digitalWrite(3, LOW);
  delay(500);  

  // run motor A backward
  digitalWrite(0, LOW);
  digitalWrite(3, HIGH);
  delay(500);

  // turn off motor A
  digitalWrite(0, LOW);
  digitalWrite(3, LOW);
  delay(500);  

  // run motor B forward
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  delay(500);
  
  // turn off motor B
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  delay(500);  

  // run motor B backward
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delay(500);

  // turn off motor B
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  delay(500);  

  // rinse and repeat
  delay(1000);
}
