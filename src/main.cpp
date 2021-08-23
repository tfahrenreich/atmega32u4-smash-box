#include <Arduino.h>

#include "Buttons.h"
#include "Inputs.h"


void setup() {
    ButtonMatrix();
}

void loop() {
    ButtonMatrix().handleMatrix();
    ButtonMatrix().printMatrix();

    processInputs();
}