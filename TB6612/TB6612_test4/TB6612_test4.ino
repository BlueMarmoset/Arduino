/*
 * Test of the Adafruit TB6612 motor/stepper driver board
 * Fourth test - separate PWM for both A and B
 */

// this is where you can declare "global" variables,
// that is variables that are visible in any method
int pinApwm = 10;
int pinA1 = 9;
int pinA2 = 8;

int pinBpwm = 5;
int pinB1 = 7;
int pinB2 = 6;

int pinTrigger = 1;
bool scriptRunning = false;

/*
 * Initial setup code
 */
void setup() {

  // set motor A pins to output
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);

  // set motor B pins to output
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);

  // set our trigger pin to input
  pinMode(pinTrigger, INPUT);
}


/*
 * Loop that runs constantly
 */
void loop() {

  // check pin 1 for input
  if (digitalRead(pinTrigger) == HIGH && !scriptRunning) {
    // run the sequence
  }
  
}


/*
 * Turn on a motor at a given speed (1 - 255), direction (true for 
 * forward, false for backward), and using the specified pin number.
 */
void runMotor(int pwm, int rate, bool forward, int pin1, int pin2) {

  // set the speed for the motor
  analogWrite(pwm, rate); 

  if (forward) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  } else {    
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }  
}


/*
 * Turn off a motor, or rather set both pins running it to low.
 */
void stopMotor(int pin1, int pin2) {  
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}


void runScript() {

  int rate = 75;
  scriptRunning = true;

  // run motor A forward slow
  runMotor(pinApwm, rate, true, pinA1, pinA2); 
  delay(250);
  stopMotor(pinA1, pinA2);
  delay(250);

  // run motor A backward slow
  runMotor(pinApwm, rate, false, pinA1, pinA2); 
  delay(250);
  stopMotor(pinA1, pinA2);
  delay(250);

  // run motor B forward slow
  runMotor(pinBpwm, rate, true, pinB1, pinB2); 
  delay(250);
  stopMotor(pinB1, pinB2);
  delay(250);

  // run motor B backward slow
  runMotor(pinBpwm, rate, false, pinB1, pinB2); 
  delay(250);
  stopMotor(pinB1, pinB2);
  delay(250);

  rate = 150;
  
  // run motor A forward medium
  runMotor(pinApwm, rate, true, pinA1, pinA2); 
  delay(250);
  stopMotor(pinA1, pinA2);
  delay(250);

  // run motor A backward medium
  runMotor(pinApwm, rate, false, pinA1, pinA2); 
  delay(250);
  stopMotor(pinA1, pinA2);
  delay(250);

  // run motor B forward medium
  runMotor(pinBpwm, rate, true, pinB1, pinB2); 
  delay(250);
  stopMotor(pinB1, pinB2);
  delay(250);

  // run motor B backward medium
  runMotor(pinBpwm, rate, false, pinB1, pinB2); 
  delay(250);
  stopMotor(pinB1, pinB2);
  delay(250);


  scriptRunning = false;
}

