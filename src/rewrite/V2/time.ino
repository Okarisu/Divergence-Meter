#include <Arduino.h>
#include <RTClib.h>

RTC_DS3231 rtc;

int FetchTime(int timeDigitWanted){

    //Pro přehlednost je čas indexován od 1 namísto 0
    DateTime now = rtc.now();

    switch (timeDigitWanted) {
        case 1:
            return now.hour() / 10;
            break;
        case 2:
            return now.hour() % 10;
            break;
        case 3:
            return now.minute() / 10;
            break;
        case 4:
            return now.minute() % 10;
            break;
        case 5:
            return now.second() / 10;
            break;
        case 6:
            return now.second() % 10;
            break;
    }
}
