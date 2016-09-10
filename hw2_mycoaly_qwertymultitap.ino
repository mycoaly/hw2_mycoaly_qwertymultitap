/*
 Serial Print Example for RedBear Duo
 Print a string character-by-character whenever a button is pressed.
 Bjoern Hartmann, 9/6/2016
 
 This example code is in the public domain.
 */

// do not use the cloud functions - assume programming through Arduino IDE
#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

const int key1 = D0;    // the number of the pushbutton pin
int key1State;             // the current reading from the input pin
int lastKey1State = LOW;   // the previous reading from the input pin

const int key2 = D1;    // the number of the pushbutton pin
int key2State;             // the current reading from the input pin
int lastKey2State = LOW;   // the previous reading from the input pin

const int key3 = D2;    // the number of the pushbutton pin
int key3State;             // the current reading from the input pin
int lastKey3State = LOW;   // the previous reading from the input pin

const int key4 = D3;    // the number of the pushbutton pin
int key4State;             // the current reading from the input pin
int lastKey4State = LOW;   // the previous reading from the input pin

const int key5 = D4;    // the number of the pushbutton pin
int key5State;             // the current reading from the input pin
int lastKey5State = LOW;   // the previous reading from the input pin

const int key6 = D8;    // the number of the pushbutton pin
int key6State;             // the current reading from the input pin
int lastKey6State = LOW;   // the previous reading from the input pin

const int key7 = D9;    // the number of the pushbutton pin
int key7State;             // the current reading from the input pin
int lastKey7State = LOW;   // the previous reading from the input pin

const int key8 = D10;    // the number of the pushbutton pin
int key8State;             // the current reading from the input pin
int lastKey8State = LOW;   // the previous reading from the input pin

const int key9 = D11;    // the number of the pushbutton pin
int key9State;             // the current reading from the input pin
int lastKey9State = LOW;   // the previous reading from the input pin

const int key10 = D12;    // the number of the pushbutton pin
int key10State;             // the current reading from the input pin
int lastKey10State = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 10;    // the debounce time; increase if the output flickers

// multi tap time span variables
long initialClickTime = 0;  // the last time pin was clicked
long clickDelay = 1000;     // timespan to register multiple clicks
int clickCounter;           // counter for clicks
int lastKey=0;             // last key pressed

void setup() {
  pinMode(key1, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key2, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key3, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key4, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key5, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key6, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key7, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key8, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key9, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  pinMode(key10, INPUT_PULLDOWN); //connect buttonPin through switch to 3.3V
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading1 = digitalRead(key1);
  int reading2 = digitalRead(key2);
  int reading3 = digitalRead(key3);
  int reading4 = digitalRead(key4);
  int reading5 = digitalRead(key5);
  int reading6 = digitalRead(key6);
  int reading7 = digitalRead(key7);
  int reading8 = digitalRead(key8);
  int reading9 = digitalRead(key9);
  int reading10 = digitalRead(key10);

  // If the switch changed, due to noise or pressing:
  if (reading1 != lastKey1State 
  or reading2 != lastKey2State
  or reading3 != lastKey3State
  or reading4 != lastKey4State
  or reading5 != lastKey5State
  or reading6 != lastKey6State
  or reading7 != lastKey7State
  or reading8 != lastKey8State
  or reading9 != lastKey9State
  or reading10 != lastKey10State) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  // If timer expires, letter printed
  if ((millis() - initialClickTime) > clickDelay){
    if (lastKey == 1){
      if (clickCounter == 1){
        Serial.print('!');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 2){
      if (clickCounter == 1){
        Serial.print('i');
      }
      else if (clickCounter == 2){
        Serial.print('o');
      }
      else if (clickCounter >= 3){
        Serial.print('p');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 3){
      if (clickCounter == 1){
        Serial.print('t');
      }
      else if (clickCounter == 2){
        Serial.print('y');
      }
      else if (clickCounter >= 3){
        Serial.print('u');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 4){
      if (clickCounter == 1){
        Serial.print('q');
      }
      else if (clickCounter == 2){
        Serial.print('w');
      }
      else if (clickCounter == 3){
        Serial.print('e');
      }
      else if (clickCounter >= 4){
        Serial.print('r');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 5){
      if (clickCounter == 1){
        Serial.print('j');
      }
      else if (clickCounter == 2){
        Serial.print('k');
      }
      else if (clickCounter >= 3){
        Serial.print('l');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 6){
      if (clickCounter == 1){
        Serial.print('f');
      }
      else if (clickCounter == 2){
        Serial.print('g');
      }
      else if (clickCounter == 3){
        Serial.print('h');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 7){
      if (clickCounter == 1){
        Serial.print('a');
      }
      else if (clickCounter == 2){
        Serial.print('s');
      }
      else if (clickCounter >= 3){
        Serial.print('d');
      }

      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 8){
      if (clickCounter == 1){
        Serial.print('b');
      }
      else if (clickCounter == 2){
        Serial.print('n');
      }
      else if (clickCounter >= 3){
        Serial.print('m');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 9){
      if (clickCounter == 1){
        Serial.print('z');
      }
      else if (clickCounter == 2){
        Serial.print('x');
      }
      else if (clickCounter == 3){
        Serial.print('c');
      }
      else if (clickCounter >= 4){
        Serial.print('v');
      }
      // reset click counter
      clickCounter = 0;
    }
    else if (lastKey == 10){
      if (clickCounter == 1){
        Serial.print(' ');
      }
      // reset click counter
      clickCounter = 0;
    }
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

//KEY 1 PRESS EVENT

    // if the button 1 state has changed:
    if (reading1 != key1State) {
      key1State = reading1;

      if (key1State == HIGH and lastKey != 1){
        lastKey = 1;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key1State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key1State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

// KEY 2 PRESS EVENT

    if (reading2 != key2State) {
    key2State = reading2;

      if (key2State == HIGH and lastKey != 2){
        lastKey = 2;
        initialClickTime = millis();
        clickCounter++;
      }
      // if button state went high and click timer already elapsed
      else if (key2State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // advance counter if the button went HIGH (was pressed)
      else if (key2State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading3 != key3State) {
      key3State = reading3;

      if (key3State == HIGH and lastKey != 3){
        lastKey = 3;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key3State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key3State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading4!= key4State) {
      key4State = reading4;

      if (key4State == HIGH and lastKey != 4){
        lastKey = 4;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key4State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key4State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading5 != key5State) {
      key5State = reading5;

      if (key5State == HIGH and lastKey != 5){
        lastKey = 5;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key5State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key5State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading6 != key6State) {
      key6State = reading6;

      if (key6State == HIGH and lastKey != 6){
        lastKey = 6;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key6State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key6State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading7 != key7State) {
      key7State = reading7;

      if (key7State == HIGH and lastKey != 7){
        lastKey = 7;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key7State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key7State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading7 != key7State) {
      key7State = reading7;

      if (key7State == HIGH and lastKey != 7){
        lastKey = 7;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key7State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key7State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading8 != key8State) {
      key8State = reading8;

      if (key8State == HIGH and lastKey != 8){
        lastKey = 8;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key8State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key8State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading9 != key9State) {
      key9State = reading9;

      if (key9State == HIGH and lastKey != 9){
        lastKey = 9;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key9State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key9State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    if (reading10 != key10State) {
      key10State = reading10;

      if (key10State == HIGH and lastKey != 10){
        lastKey = 10;
        initialClickTime = millis();
        clickCounter=1;
      }
      // if button state is HIGH and click timer already elapsed
      else if (key10State == HIGH and (millis() - initialClickTime) > clickDelay){
        // reset click timer
        initialClickTime = millis();
        clickCounter++;
      }      
      // additional clicks added to counter if HIGH
      else if (key10State == HIGH and (millis() - initialClickTime) <= clickDelay) {
        clickCounter++;
      }
    }

    
  }

  // save the reading.
  lastKey1State = reading1;
  lastKey2State = reading2;
  lastKey3State = reading3;
  lastKey4State = reading4;
  lastKey5State = reading5;
  lastKey6State = reading6;
  lastKey7State = reading7;
  lastKey8State = reading8;
  lastKey9State = reading9;
  lastKey10State = reading10;
}

