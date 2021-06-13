

#include <SoftwareSerial.h>
#define RX 11
#define TX 10

#include "LedControl.h"
#define DIN 12
#define CS 9
#define CLK 13

boolean scramble = false;
boolean alpha = false;
boolean beta = false;
SoftwareSerial bluetooth(TX, RX);

void setup()
{
    bluetooth.begin(9600);
    setChar(0, 6, ., false);
}

void loop()
{

    //BT logic
    byte BluetoothData;

    if (bluetooth.available() > 0)
    {

        BluetoothData = bluetooth.read();

        switch (BluetoothData)
        {

        case 'scramble':
            scramble = true;
            break;
        case 'alpha':
            alpha = true;
            break;
        case 'beta':
            beta = true;
            break;

        default:
            bluetooth.println("Invalid command.");
        }
    }

    //call fc

    if (scramble)
    {
        scramble();
        scramble = false;
    }
    if (alpha)
    {
        alpha();
        alpha = false;
    }
    if (beta)
    {
        beta();
        beta = false;
    }
}

void scramble()
{
    setDigit(0, 7, 1, false);
}
void alpha()
{
    setDigit(0, 7, 0, false);
}
void beta()
{
    setDigit(0, 7, 1, false);
}