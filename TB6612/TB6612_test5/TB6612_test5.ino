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

int powerPin = 11;

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

  // set power pin to something close to 3.3v
  analogWrite(powerPin, 168);
}


/*
 * Loop that runs constantly
 */
void loop() {

  // check pin 1 for input
  if (digitalRead(pinTrigger) == LOW && !scriptRunning) {

    // ignore other input
    scriptRunning = true;
    
    // run the script
    runScript();

    // ignore other input
    scriptRunning = false;
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

  // Rate of speed as measured in 1-255. 
  // What this means varies based on voltage.
  // Currently working with a 9 volt battery.
  int rate = 50;

  // Turn duration for a right angle turn. This
  // also varies based on voltage AND the rate used.
  // This is milliseconds it will take at that rate.
  // int turnDuration = 1250;

  // update - my right turn seems shallow so I will
  // separate each turn into different durations in
  // order to spend longer on the right turn
  int leftTurn = 1250;
  int rightTurn = 1350;

  // forward
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(2000);

  // left
  runMotor(pinApwm, rate, false, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(leftTurn);
  
  // forward
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(1000);
   
  // right
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, false, pinB1, pinB2);
  delay(rightTurn);

  // forward
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(2000);

  // right
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, false, pinB1, pinB2);
  delay(rightTurn);

  // forward
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(1000);

  // left
  runMotor(pinApwm, rate, false, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(leftTurn);

  // forward
  runMotor(pinApwm, rate, true, pinA1, pinA2);
  runMotor(pinBpwm, rate, true, pinB1, pinB2);
  delay(2000);

  stopMotor(pinA1, pinA2);
  stopMotor(pinB1, pinB2);
}

