
#define RX 11
#define TX 10
#define pinLED 13
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(TX, RX);

void setup()
{
    bluetooth.begin(9600);
    bluetooth.println("Arduino zapnuto, test Bluetooth..");
}

void logic()
{
    byte BluetoothData;

    if (bluetooth.available() > 0)
    {
        BluetoothData = bluetooth.read();

        switch (BluetoothData)
        {

        case '0':
            break;

        default:
            bluetooth.println("Neznamy prikaz.");
        }
    }
    delay(100);
}