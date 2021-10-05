int switchCount = 0;
int state[3] = {0, 0, 0};
int lastState[3] = {0, 0, 0};
int controlState[3] = {0, 0, 0};

void setup()
{
  //buttons
  for(int pinNumber = 2; pinNumber<5; pinNumber++) {
    pinMode(pinNumber, INPUT);
  }
  
  //LEDs
  for(int pinNumber = 5; pinNumber<14; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop()
{
  //check input states
  for(int i = 0; i<3; i++) {
    state[i] = digitalRead(i+2);
  }
  
  //toggle states:
  //for each button
  for(int i = 0; i<3; i++) {
    //if it is newly pressed
    if(state[i] == 1 && lastState[i] == 0) {
      //and it is currently OFF
      if(controlState[i] == 0) {
        //turn ON
        controlState[i] = 1;
      }
      //else if it is currently ON
      else {
        //turn OFF
        controlState[i] = 0;
      }
    }
  }
  
  //update states
  for(int i = 0; i<3; i++) {
    lastState[i] = state[i];
  }
  
  //button count
  switchCount = controlState[0] + controlState[1] + controlState[2];
  
  //0 button pressed = no lights
  if(switchCount == 0) {
    for(int pinNumber = 5; pinNumber<14; pinNumber++) {
      digitalWrite(pinNumber, LOW);
  	}
  }
  
  //any 1 button pressed = red lights
  else if(switchCount == 1) {
    for(int pinNumber = 5; pinNumber<14; pinNumber++) {
      digitalWrite(pinNumber, LOW);
  	}
    for(int pinNumber = 5; pinNumber<8; pinNumber++) {
      digitalWrite(pinNumber, HIGH);
    }
  }
  
  //2 buttons pressed = yellow lights only
  else if(switchCount == 2) {
    for(int pinNumber = 5; pinNumber<14; pinNumber++) {
      digitalWrite(pinNumber, LOW);
  	}
    for(int pinNumber = 8; pinNumber<11; pinNumber++) {
      digitalWrite(pinNumber, HIGH);
    }
  }
  
  //3 buttons pressed = green lights only
  else if(switchCount == 3) {
    for(int pinNumber = 5; pinNumber<14; pinNumber++) {
      digitalWrite(pinNumber, LOW);
  	}
    for(int pinNumber = 11; pinNumber<14; pinNumber++) {
      digitalWrite(pinNumber, HIGH);
    }
  }
  
  delay(100);
}