#include <Arduino.h>
#include "symbols.h"
#include "matrix.h"

void Controller(bool divergence) {
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

        Display(divergenceArray[]);

    } else {

    }

}