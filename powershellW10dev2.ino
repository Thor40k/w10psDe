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
    // this is generally not necessary but with some older systems it seems to
    // prevent missing the first character after a delay:
    DigiKeyboard.sendKeyStroke(0);

    // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
    // if doing keyboard stuff because it keeps talking to the computer to make
    // sure the computer knows the keyboard is alive and connected
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
  digitalWrite(1, HIGH); //LED an
  DigiKeyboard.delay(2000);
  digitalWrite(1, LOW);
  }
  delay(1000);
  iterationCounter++;
}
