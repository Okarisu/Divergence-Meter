
#define RX 11
#define TX 10
#define pinLED 13
#include <SoftwareSerial.h>

boolean scramble = false;
boolean alpha = false;
boolean beta = false;
SoftwareSerial bluetooth(TX, RX);

void setup()
{
    bluetooth.begin(9600);
}

void logic()
{
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
    delay(100);
}