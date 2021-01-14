#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

int num1[] = {0, 1, 2, 3, 4, 5, 6};
int pozice[] = {7, 5, 4, 3, 2, 1, 0};

void setup()
{

    lc.shutdown(0, false); //Wakeup call

    lc.setIntensity(0, 8); // Set the brightness to a medium values

    lc.clearDisplay(0); //Clear

    //   int pole[] = {0, 1, 2, 3, 4, 5, 6};
}

void loop()
{
    lc.setChar(0, 6, '.', false);

    for (pozice = 0; pozice <= 7; pozice++)
    {
        lc.setDigit(0, pozice[0], num[0], false);
        num++;
    } přepni na pole 2



 /*   lc.setDigit(0, 7, 0, false);
    lc.setChar(0, 6, '.', false);
    lc.setDigit(0, 5, 5, false);
    lc.setDigit(0, 4, 7, false);
    lc.setDigit(0, 3, 1, false);
    lc.setDigit(0, 2, 0, false);
    lc.setDigit(0, 1, 2, false);
    lc.setDigit(0, 0, 4, false);
    */
