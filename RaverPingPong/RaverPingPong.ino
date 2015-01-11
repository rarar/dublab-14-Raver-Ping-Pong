#define REDPIN_L 3 
#define GREENPIN_L 5
#define BLUEPIN_L 6

#define REDPIN_R 9
#define GREENPIN_R 10
#define BLUEPIN_R 11

#define FADESPEED 15     // make this higher to slow down

void setup() {
  Serial.begin(9600);
  pinMode(REDPIN_L, OUTPUT);
  pinMode(GREENPIN_L, OUTPUT);
  pinMode(BLUEPIN_L, OUTPUT);
  //
  pinMode(REDPIN_R, OUTPUT);
  pinMode(GREENPIN_R, OUTPUT);
  pinMode(BLUEPIN_R, OUTPUT);
}

void flashBurst(boolean turnOn) {

  if (turnOn) {
    analogWrite(REDPIN_L, random(255));
    analogWrite(REDPIN_R, random(255));

    analogWrite(BLUEPIN_L, random(255));
    analogWrite(BLUEPIN_R, random(255));

    analogWrite(GREENPIN_L, random(255));
    analogWrite(GREENPIN_R, random(255)); 
  } 
  else {
    analogWrite(REDPIN_L, 0);
    analogWrite(REDPIN_R, 0);

    analogWrite(BLUEPIN_L, 0);
    analogWrite(BLUEPIN_R, 0);

    analogWrite(GREENPIN_L, 0);
    analogWrite(GREENPIN_R, 0); 
  }
  delay(50);
}

void loop() {
  
  flashBurst(false);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    Serial.println(inChar);
    if (inChar=='A') {
      flashBurst(true);
    } 
  }
}












