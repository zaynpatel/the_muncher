#include <ezButton.h>

ezButton limitSwitch(17);  // use 17 for testing

void setup() {
  Serial.begin(9600);
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  limitSwitch.loop(); // MUST call the loop() function first

  if(limitSwitch.isPressed())
    Serial.println("The limit switch: UNTOUCHED -> TOUCHED");

  if(limitSwitch.isReleased())
    Serial.println("The limit switch: TOUCHED -> UNTOUCHED");

  int state = limitSwitch.getState();
  if(state == HIGH)
    Serial.println("The limit switch: UNTOUCHED");
  else
    Serial.println("The limit switch: TOUCHED");
}
