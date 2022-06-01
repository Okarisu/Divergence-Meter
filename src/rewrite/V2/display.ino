#include <Arduino.h>
#include "define.h"

void Display(byte digitsToDisplay[8]) {

    //Pole k rozsvěcení jednotlivých trubic
    byte gridsPowerOrder[8] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

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
