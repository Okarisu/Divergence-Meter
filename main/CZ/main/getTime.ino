#include "RTClib.h"

RTC_DS3231 rtc;

void getTime()
{
    byte displayStroke = B11111101;

    byte timeDatabase[] = {

        B00000011, B10011111,
        B00100101, B00001101,
        B10110001, B01001001,
        B01000001, B00011111,
        B00000001, B00001001

    };

    int hours;
    int minutes;
    int seconds;

    int hours1;
    int hoursS;
    int minutes1;
    int minutes2;
    int seconds1;
    int seconds2;

    DateTime now = rtc.now();

    hours = now.hour();
    minutes = now.minute();
    seconds = now.second();

    hours1 = hours / 10;
    hours2 = hours % 10;

    minutes1 = minutes / 10;
    minutes2 = minutes % 10;

    seconds1 = seconds / 10;
    seconds2 = seconds % 10;

    divergenceArray[] = {timeDatabase[hours1], timeDatabase[hours2], displayStroke, timeDatabase[minutes1], timeDatabase[minutes2], displayStroke, timeDatabase[seconds1], timeDatabase[seconds2]};

    display();
}