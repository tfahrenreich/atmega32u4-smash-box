//
// Created by Timothy Fahrenreich on 8/19/21.
//

#pragma once

typedef struct {
    bool y;
    bool x;
    bool b;
    bool a;
    bool l;
    bool r;
    bool zl;
    bool zr;
    bool up;
    bool down;
    bool right;
    bool left;
    bool mod_x;
    bool mod_y;
    bool c_left;
    bool c_right;
    bool c_up;
    bool c_down;
    bool plus;
    bool minus;
    bool home;
} ButtonsState;

class ButtonMatrix_ {
private:
    ButtonsState _controllerState{};
public:
    ButtonMatrix_();

    static void setupButtons();

    void assignButtonValues();

    void handleMatrix();

    void printMatrix();

    ButtonsState getButtonsState();

};


ButtonMatrix_ &ButtonMatrix();