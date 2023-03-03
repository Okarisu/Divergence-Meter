/*
Sketch to be uploaded only once to initialise time in RTC module.
Then, the src code is uploaded in arduino board, time in RTC is already set.
*/

#include <Wire.h>
#include <DS3231.h>
DS3231 rtc;
RTCDateTime dateTime;

void setup()
{

    Serial.begin(9600);
    rtc.begin();
    rtc.setDateTime(__DATE__, __TIME__);
}