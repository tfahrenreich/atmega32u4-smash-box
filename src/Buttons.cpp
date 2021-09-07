//
// Created by Timothy Fahrenreich on 8/19/21.
//

#include <Arduino.h>
#include "Buttons.h"


byte rows[3] = {2, 3, 4};
byte cols[7] = {21, 20, 19, 18, 15, 14, 16};
const int rowCount = sizeof(rows) / sizeof(rows[0]);
const int colCount = sizeof(cols) / sizeof(cols[0]);

byte keys[colCount][rowCount];

ButtonMatrix_::ButtonMatrix_() {
    _controllerState.a = false;
    _controllerState.b = false;
    _controllerState.x = false;
    _controllerState.l = false;
    _controllerState.r = false;
    _controllerState.y = false;
    _controllerState.zl = false;
    _controllerState.zr = false;
    _controllerState.down = false;
    _controllerState.left = false;
    _controllerState.right = false;
    _controllerState.up = false;
    _controllerState.mod_x = false;
    _controllerState.mod_y = false;
    _controllerState.c_left = false;
    _controllerState.c_right = false;
    _controllerState.c_up = false;
    _controllerState.c_down = false;
    _controllerState.plus = false;
    _controllerState.minus = false;
    _controllerState.home = false;
    ButtonMatrix_::setupButtons();
};

void ButtonMatrix_::setupButtons() {
    Serial.begin(115200);

    for (unsigned char row: rows) {
        Serial.print(row);
        pinMode(row, INPUT);
    }
    for (unsigned char col: cols) {
        Serial.print(col);
        pinMode(col, INPUT_PULLUP);
    }
};

void ButtonMatrix_::assignButtonValues() {

    _controllerState.up = keys[3][2];
    _controllerState.down = keys[4][2];
    _controllerState.left = keys[5][2];
    _controllerState.right = keys[2][2];
    _controllerState.l = keys[6][2];

    _controllerState.mod_y = keys[1][2];
    _controllerState.mod_x = keys[2][1];
    _controllerState.plus = keys[6][0];
    _controllerState.minus = keys[6][1];
    _controllerState.home = keys[5][1];

    _controllerState.a = keys[0][0];
    _controllerState.c_left = keys[1][1];
    _controllerState.c_right = keys[4][1];
    _controllerState.c_up = keys[0][2];
    _controllerState.c_down = keys[0][1];

    _controllerState.b = keys[5][0];
    _controllerState.r = keys[4][0];
    _controllerState.y = keys[3][0];
    _controllerState.x = keys[1][0];

//    _controllerState.zl = keys[4][0];
//    _controllerState.zr = keys[0][1];
};

void ButtonMatrix_::handleMatrix() {
    for (int colIndex = 0; colIndex < colCount; colIndex++) {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);

        for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = (digitalRead(rowCol) == LOW);
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
    ButtonMatrix_::assignButtonValues();
};

void ButtonMatrix_::printMatrix() {
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        if (rowIndex < 10)
            Serial.print(F("0"));
        Serial.print(rowIndex);
        Serial.print(F(": "));

        for (int colIndex = 0; colIndex < colCount; colIndex++) {
            Serial.print(keys[colIndex][rowIndex]);
            if (colIndex < colCount)
                Serial.print(F(", "));
        }
        Serial.println("");
    }
    Serial.println("");
}

ButtonsState ButtonMatrix_::getButtonsState() {
    return _controllerState;
}

ButtonMatrix_ &ButtonMatrix() {
    static ButtonMatrix_ obj;
    return obj;
}
