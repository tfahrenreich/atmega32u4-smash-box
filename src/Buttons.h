//
// Created by Timothy Fahrenreich on 8/19/21.
//

#ifndef ATMEGA32U4_SMASH_BOX_BUTTONS_H
#define ATMEGA32U4_SMASH_BOX_BUTTONS_H
//#pragma once

struct ButtonsState {
    bool y = false;
    bool x = false;
    bool b = false;
    bool a = false;
    bool l = false;
    bool r = false;
    bool zl = false;
    bool zr = false;
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
    bool mod_x = false;
    bool mod_y = false;
    bool c_left = false;
    bool c_right = false;
    bool c_up = false;
    bool c_down = false;
    bool plus = false;
    bool minus = false;
    bool home = false;
};

class ButtonMatrix {
private:
    static void assignButtonValues();

public:
    static ButtonsState _controllerState;

    static void setupButtons();

    static void handleMatrix();

};


#endif //ATMEGA32U4_SMASH_BOX_BUTTONS_H
