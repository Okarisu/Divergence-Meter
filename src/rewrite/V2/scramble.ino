#include <Arduino.h>
#include "define.h"
#include "matrix.h"

void Scramble(){

    unsigned int startTime = millis();
    unsigned int stopTime = startTime + scrambleLength;

    while(millis() < stopTime){
        byte scrambleArray[8] = {
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)]
        };
        Display(scrambleArray);
    }


}
