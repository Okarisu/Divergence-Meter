#include <SoftwareSerial.h>
//#include "HC05.h"

//#define RX 2;
//#define TX 3;

SoftwareSerial bluetooth(2, 3);

byte bluetooth_input;

void switches()
{

    if (!(digitalRead(power_switch_pin) || digitalRead(display_switch_pin) || digitalRead(scramble_switch_pin)))
    {
        long push_timer = millis();
        int push_length;
        int push_limit = 25;

        while (!digitalRead(power_switch_pin))
        {
            push_length = millis() - push_timer;
        }
        if (push_length >= push_limit)
        {
            power = !power;
            push_length = 0;
        }

        while (!digitalRead(display_switch_pin))
        {
            push_length = millis() - push_timer;
        }
        if (push_length >= push_limit)
        {
            show_divergence = !show_divergence;
            push_length = 0;
        }

        while (!digitalRead(scramble_switch_pin))
        {
            push_length = millis() - push_timer;
        }
        if (push_length >= push_limit)
        {
            do_scramble = true;
            push_length = 0;
        }
    }
}

void bluetoothFce()
{

    if (bluetooth.available())
    {

        bluetooth_input = bluetooth.read();

        switch (bluetooth_input)
        {

        //power
        case 'pwr':
            power = !power;
            break;
        case 'on':
            power = true;
            break;
        case 'off':
            power = false;
            break;

        //div || time
        case 'div':
            show_divergence = true;
            break;
        case 'time':
            show_divergence = false;
            break;

        //scramble
        case 'scramble':
            do_scramble = true;
            break;

        default:
            bluetooth.println("Illegal argument");
        }
    }
    delay(10);
}
