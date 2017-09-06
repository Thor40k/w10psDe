#include "DigiKeyboard.h"

// Delay between keystrokes
#define KEYSTROKE_DELAY 1000


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
  DigiKeyboard.sendKeyStroke(21,128); //R + Windows Taste
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("powershell Start/Process cmd /Verb runAs"); //Powershell als Admin
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Z, MOD_ALT_LEFT); // ALT-J für System deutsches KB, US Sparche
  //DigiKeyboard.sendKeyStroke(28,64); //Y + right ALT
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("mode con>cols)18 lines)1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("ping /t heise.de");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, HIGH); //LED an
  DigiKeyboard.delay(2000);
  digitalWrite(1, LOW);
  }
  delay(1000);
  iterationCounter++;
}
