#include <Arduino.h>

#include "Buttons.h"
#include "Inputs.h"


void setup() {
    ButtonMatrix();
}

void loop() {
//    delay(100);
//    ButtonMatrix().printMatrix();

    ButtonMatrix().handleMatrix();
    processInputs();
}