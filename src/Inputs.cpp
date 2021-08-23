//
// Created by Timothy Fahrenreich on 8/23/21.
//

#include <SwitchControlLibrary.h>
#include "Inputs.h"
#include "Buttons.h"

void resetButtons() {
    SwitchControlLibrary().releaseButton(Button::A);
    SwitchControlLibrary().releaseButton(Button::B);
    SwitchControlLibrary().releaseButton(Button::X);
    SwitchControlLibrary().releaseButton(Button::Y);
    SwitchControlLibrary().releaseButton(Button::L);
    SwitchControlLibrary().releaseButton(Button::R);
    SwitchControlLibrary().releaseButton(Button::_ZL);
    SwitchControlLibrary().releaseButton(Button::ZR);
    SwitchControlLibrary().releaseButton(Button::HOME);
    SwitchControlLibrary().releaseButton(Button::MINUS);
    SwitchControlLibrary().releaseButton(Button::PLUS);
}

void nonModifierButtons(ButtonsState bs) {
    if (bs.a) SwitchControlLibrary().pressButton(Button::A);
    if (bs.b) SwitchControlLibrary().pressButton(Button::B);
    if (bs.x) SwitchControlLibrary().pressButton(Button::X);
    if (bs.y) SwitchControlLibrary().pressButton(Button::Y);
    if (bs.l) SwitchControlLibrary().pressButton(Button::L);
    if (bs.r) SwitchControlLibrary().pressButton(Button::R);
    if (bs.zl) SwitchControlLibrary().pressButton(Button::_ZL);
    if (bs.zr) SwitchControlLibrary().pressButton(Button::ZR);
    if (bs.home) SwitchControlLibrary().pressButton(Button::HOME);
    if (bs.minus) SwitchControlLibrary().pressButton(Button::MINUS);
    if (bs.plus) SwitchControlLibrary().pressButton(Button::PLUS);
}

void LStick(ButtonsState bs) {
    uint8_t lx = 128, ly = 128;

    if (bs.left) {
        lx = 64;
    } else if (bs.right) {
        lx = 192;
    }

    if (bs.up) {
        ly = 64;
    } else if (bs.down) {
        ly = 192;
    }

    SwitchControlLibrary().moveLeftStick(lx, ly);
}

void CStick(ButtonsState bs) {
    uint8_t rx = 128, ry = 128;

    if (bs.left) {
        rx = 64;
    } else if (bs.right) {
        rx = 192;
    }

    if (bs.up) {
        ry = 64;
    } else if (bs.down) {
        ry = 192;
    }

    SwitchControlLibrary().moveRightStick(rx, ry);
}

void processInputs() {
    ButtonsState buttonsState = ButtonMatrix().getButtonsState();

    resetButtons();
    nonModifierButtons(buttonsState);

    LStick(buttonsState);
    CStick(buttonsState);

    SwitchControlLibrary().sendReport();
}

