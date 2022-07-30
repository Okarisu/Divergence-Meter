#include <Arduino.h>
#include "define.h"
#include "controller.ino"
#include "scramble.ino"

bool divergence = false;

void setup() {

}

void loop() {

    Controller(divergence);

    if (!(digitalRead(modeSwitch) || digitalRead(scrambleSwitch))) {
        long pushTimer = millis();
        int pushLength;
        int push_limit = 25;

        while (!digitalRead(modeSwitch)) {
            pushLength = millis() - pushTimer;
        }
        if (pushLength >= push_limit) {
            divergence = !divergence;
            pushLength = 0;
        }

        while (!digitalRead(scrambleSwitch)) {
            pushLength = millis() - pushTimer;
        }
        if (pushLength >= push_limit) {
            Scramble();
            pushLength = 0;
        }

    }
}