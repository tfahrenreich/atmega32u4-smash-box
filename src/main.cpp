#include <Arduino.h>
//#include <NintendoSwitchControlLibrary.h>
#include <SwitchControlLibrary.h>

#define BOUNCE_WITH_PROMPT_DETECTION

#include <Bounce2.h>

#define MILLIDEBOUNCE 1 //Debounce time in milliseconds
#define pinOBLED 21  //Onboard LED pin

#define A_MASK_ON 0x04
#define B_MASK_ON 0x02
#define BUTTONA 4
#define BUTTONB 5

Bounce buttonA = Bounce();
Bounce buttonB = Bounce();

byte buttonStatus[15];

void setup() {
//    pushButton(Button::B, 500, 5);
    Serial.begin(115200);
    buttonA.attach(5, INPUT_PULLUP);
    buttonB.attach(4, INPUT_PULLUP);

    buttonA.interval(MILLIDEBOUNCE);
    buttonB.interval(MILLIDEBOUNCE);

    pinMode(pinOBLED, OUTPUT);
    //Set the LED to low to make sure it is off
    digitalWrite(pinOBLED, HIGH);
}


void update() {
    if (buttonA.update()) {
        buttonStatus[BUTTONA] = buttonA.fell();
        Serial.println("A - update");
    }
    if (buttonB.update()) {
        buttonStatus[BUTTONB] = buttonB.fell();
        Serial.println("B - update");
    }
}

void process() {
    if (buttonStatus[BUTTONA]) {
        SwitchControlLibrary().pressButton(Button::A);
        Serial.println("A - process");
    }

    if (buttonStatus[BUTTONB]) {
        SwitchControlLibrary().pressButton(Button::B);
        Serial.println("B - process");
    }
}


void clearButtons() {

    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().releaseButton(Button::B);
    SwitchControlLibrary().releaseButton(Button::X);
    SwitchControlLibrary().releaseButton(Button::Y);
}

void loop() {
    clearButtons();

    update();
    process();
    SwitchControlLibrary().sendReport();
}