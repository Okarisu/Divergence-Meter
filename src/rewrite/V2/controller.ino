#include <Arduino.h>
#include "byte_lib.h"
#include "matrix.h"
#include "fetch_time.ino"
#include "display.ino"

void Controller (bool divergence) {
    if (divergence) {
        byte divergenceArray[8] = {
                matrix[random(0, 10)],
                symDot,
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)],
                matrix[random(0, 10)]
        };
        Display(divergenceArray);

    } else {

        byte timeArray[8] = {
                matrix[FetchTime(1)],
                matrix[FetchTime(2)],
                symStroke,
                matrix[FetchTime(3)],
                matrix[FetchTime(4)],
                symStroke,
                matrix[FetchTime(5)],
                matrix[FetchTime(6)],
        };

        Display(timeArray);

    }

}