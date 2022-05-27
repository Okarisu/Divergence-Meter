#include <SoftwareSerial.h>
//#include "HC05.h"

#define RX 2;
#define TX 3;

SoftwareSerial bluetooth(TX, RX);

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

byte bluetooth_input;

void bluetoothFce()
{

    if (bluetooth.available())
    {

        bluetooth_input = bluetooth.read();

        switch (bluetooth_input)
        {
            //help
        case 'h':
            bluetooth.println("p - switch power");
            bluetooth.println("1 - power ON");
            bluetooth.println("0 - power OFF");
            bluetooth.println("0 - power OFF");
            bluetooth.println("d - show divergence");
            bluetooth.println("t - show time");
            bluetooth.println("s - scramble");
            bluetooth.println("f - system stats - BT");
            bluetooth.println("\f - system stats - serial");
            bluetooth.println("h - help");
            break;

        //power
        case 'p':
            power = !power;
            bluetooth.print("Power switched. ");
            if (power)
            {
                bluetooth.println("Power ON.");
            }
            else
            {
                bluetooth.println("Power OFF.");
            }
            break;
        case '1':
            power = true;
            bluetooth.println("Power ON.");
            break;
        case '0':
            power = false;
            bluetooth.println("Power OFF.");
            break;

        //div || time
        case 'd':
            show_divergence = true;
            break;
        case 't':
            show_divergence = false;
            break;

        //scramble
        case 's':
            do_scramble = true;
            break;
        case 'f':
            float runtimeSeconds = millis() / 1000;

            bluetooth.print("Temperature: ");
            bluetooth.print(rtc.getTemperature());
            bluetooth.println(" C");
            bluetooth.println("--------");
            bluetooth.print("System runtime: ");
            bluetooth.print(runtimeSeconds / 60);
            bluetooth.print(" minutes - aprox ");
            bluetooth.print(runtimeSeconds / 3600);
            bluetooth.print(" hours - aprox ");
            bluetooth.print(runtimeSeconds / 86400);
            bluetooth.print(" days.");

            break;
        case '\f':
            float runtimeSeconds = millis() / 1000;

            Serial.print("Temperature: ");
            Serial.print(rtc.getTemperature());
            Serial.println(" C");
            Serial.println("--------");
            Serial.print("System runtime: ");
            Serial.print(runtimeSeconds / 60);
            Serial.print(" minutes - aprox ");
            Serial.print(runtimeSeconds / 3600);
            Serial.print(" hours - aprox ");
            Serial.print(runtimeSeconds / 86400);
            Serial.print(" days.");

            break;

        default:
            bluetooth.println("ILLEGAL ARGUMENT");
        }
    }
    delay(10);
}
