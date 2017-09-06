#include "DigiKeyboard.h"

// Delay between keystrokes
#define KEYSTROKE_DELAY 1000
#define KEY_UP_ARROW   0x52
#define KEY_DOWN_ARROW   0x51
#define KEY_LEFT_ARROW   0x50
#define KEY_RIGHT_ARROW   0x4F

#define  KEY_ESC         0x29  // Escape
#define KEY_MODIFIER_LEFT_GUI 0x08

int iterationCounter = 0;

void loop(){
}

void setup(){

  pinMode(1, OUTPUT); //LED 
  
  DigiKeyboard.update();
  if (iterationCounter == 0) {
    
    DigiKeyboard.sendKeyStroke(0);

    DigiKeyboard.delay(KEYSTROKE_DELAY);

  DigiKeyboard.delay(6000);
  DigiKeyboard.sendKeyStroke(21,128); //R + Windows Keys
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("powershell Start/Process cmd /Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Z, MOD_ALT_LEFT); // ALT-J 
  //DigiKeyboard.sendKeyStroke(28,64); //Y + right ALT
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("mode con>cols)18 lines)1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("ping /t heise.de");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW, MOD_GUI_LEFT);
  digitalWrite(1, HIGH); //LED an
  DigiKeyboard.delay(2000);
  digitalWrite(1, LOW);
  }
  delay(1000);
  iterationCounter++;
}
