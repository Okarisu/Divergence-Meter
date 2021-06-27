#include <Wire.h>
#include <DS3231.h>
DS3231 rtc;
RTCDateTime datumCas;

void setup()
{

    Serial.begin(9600);
    rtc.begin();
    rtc.setDateTime(__DATE__, __TIME__);
}