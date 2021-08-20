//
// Created by Timothy Fahrenreich on 8/19/21.
//

#include <Arduino.h>
#include "Buttons.h"


byte rows[3] = {2, 3, 4};
byte cols[7] = {8, 9, 10, 20, 19, 18, 17};
const int rowCount = sizeof(rows) / sizeof(rows[0]);
const int colCount = sizeof(cols) / sizeof(cols[0]);

byte keys[colCount][rowCount];

void ButtonMatrix::setupButtons() {
    Serial.begin(115200);

    for (unsigned char row : rows) {
        Serial.print(row);
        pinMode(row, INPUT);
    }
    for (unsigned char col : cols) {
        Serial.print(col);
        pinMode(col, INPUT_PULLUP);
    }
}


void ButtonMatrix::assignButtonValues() {
    _controllerState.y = keys[0][0];
    _controllerState.x = keys[1][0];
    _controllerState.b = keys[2][0];
    _controllerState.a = keys[3][0];
    _controllerState.l = keys[4][0];
    _controllerState.r = keys[5][0];
    _controllerState.zl = keys[6][0];

    _controllerState.zr = keys[0][1];
    _controllerState.up = keys[1][1];
    _controllerState.down = keys[2][1];
    _controllerState.right = keys[3][1];
    _controllerState.left = keys[4][1];
    _controllerState.mod_x = keys[5][1];
    _controllerState.mod_y = keys[6][1];

    _controllerState.c_left = keys[0][2];
    _controllerState.c_right = keys[1][2];
    _controllerState.c_up = keys[2][2];
    _controllerState.c_down = keys[3][2];
    _controllerState.plus = keys[4][2];
    _controllerState.minus = keys[5][2];
    _controllerState.home = keys[6][2];
};

void ButtonMatrix::handleMatrix() {
    for (int colIndex = 0; colIndex < colCount; colIndex++) {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);

        for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
    ButtonMatrix::assignButtonValues();
};