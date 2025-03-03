//Uses 'Arduino Micro' board designation.

//D10,11 buttons

const short NUM_BUTTONS = 2;
const short NUM_POTS = 4;

#include "Keyboard.h"
#include "fastbutton.h"

Button gButtons[NUM_BUTTONS];

void setup() {
  //Buttons left to right and encoder button. (PIN, pullup ON)
  gButtons[0].init( 9, true);
  gButtons[1].init( 10, true);
}

void handleButtons()
{
  //for (int i=0;i<NUM_BUTTONS;++i)
  int newstate;
  int state;
  int i;

  for (i=0;i<NUM_BUTTONS;++i)
  {
    newstate = -1;
    state = gButtons[i].getStatus();
    
    if (state != Button::UNDEF )
    {
      Keyboard.press(KEY_LEFT_SHIFT);
      if (i==0)
      {
        Keyboard.press(KEY_DOWN_ARROW);
      }
      else
      {
        Keyboard.press(KEY_UP_ARROW);
      }
      delay(50);
      Keyboard.releaseAll();
    }
  }
}

void loop() {
   handleButtons();
}
