#include <Arduino.h>
#include "define.h"
#include "byte_lib.h"

void Display(byte digitsToDisplay[]) {

    //Pole k rozsvěcení jednotlivých trubic
    byte gridsPowerOrder[8] = {grid1, grid2, grid3, grid4, grid5, grid6, grid7, grid8};

    for (int currentDisplayPosition = 0; currentDisplayPosition < 8; currentDisplayPosition += 1) {

        digitalWrite(segmentLatchPin, LOW);
        digitalWrite(gridLatchPin, LOW);

        //Odeslání dat
        shiftOut(segmentDataPin, segmentClockPin, LSBFIRST, digitsToDisplay[currentDisplayPosition]);
        shiftOut(gridDataPin, gridClockPin, LSBFIRST, gridsPowerOrder[currentDisplayPosition]);

        digitalWrite(segmentLatchPin, HIGH);
        digitalWrite(gridLatchPin, HIGH);

        delay(displayCycleDelay); //Pokud nebude fungovat, zkusit Timer
    }
}
