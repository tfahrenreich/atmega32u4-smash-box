//
// Created by Timothy Fahrenreich on 8/19/21.
//

#include <Arduino.h>
#include "Buttons.h"
#include <Bounce2.h>

byte rows[] = {2, 3, 4};
const int rowCount = sizeof(rows) / sizeof(rows[0]);

byte cols[] = {8, 9, 10};
const int colCount = sizeof(cols) / sizeof(cols[0]);

byte keys[colCount][rowCount];

Bounce bRows[] = {
        Bounce(),
        Bounce(),
        Bounce(),
};
Bounce bCols[] = {
        Bounce(),
        Bounce(),
        Bounce(),
};

void setupButtons() {
    for (int i = 0; i < rowCount; i++) {
        Serial.print(rows[i]);
        Serial.println(" as input");
        bRows[i].attach(rows[i], INPUT);
    }

    for (int i = 0; i < colCount; i++) {
        Serial.print(cols[i]);
        Serial.println(" as input-pullup");
        bCols[i].attach(cols[i], INPUT_PULLUP);
    }
}

void readMatrix() {
    bCols->update();
    bRows->update();
    for (int colIndex = 0; colIndex < colCount; colIndex++) {
        byte curColPin = cols[colIndex];
        pinMode(curColPin, OUTPUT);
        digitalWrite(curColPin, LOW);

        for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            byte rowColPin = rows[rowIndex];
            pinMode(rowColPin, INPUT_PULLUP);
            keys[colIndex][rowIndex] = bCols[colIndex].read();
            pinMode(rowColPin, INPUT);
        }
        pinMode(curColPin, INPUT);
    }
}

void printMatrix() {
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