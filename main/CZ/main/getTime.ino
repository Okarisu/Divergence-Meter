#include <RTClib.h>

RTC_DS3231 rtc;

void getTime()
{
    byte displayStroke = B11111101;

    byte time_database[] = {

        B00000011, B10011111,
        B00100101, B00001101,
        B10110001, B01001001,
        B01000001, B00011111,
        B00000001, B00001001

    };

    int hours;
    int minutes;
    int seconds;

    int hoursOne;
    int hoursTwo;
    int minutesOne;
    int minutesTwo;
    int secondsOne;
    int secondsTwo;

    DateTime now = rtc.now();

    hours = now.hour();
    minutes = now.minute();
    seconds = now.second();

    hoursOne = hours / 10;
    hoursTwo = hours % 10;

    minutesOne = minutes / 10;
    minutesTwo = minutes % 10;

    secondsOne = seconds / 10;
    secondsTwo = seconds % 10;

    display_array[0] = time_database[hoursOne];
    display_array[1] = time_database[hoursTwo];
    display_array[2] = displayStroke;
    display_array[3] = time_database[minutesOne];
    display_array[4] = time_database[minutesTwo];
    display_array[5] = displayStroke;
    display_array[6] = time_database[secondsOne];
    display_array[6] = time_database[secondsTwo];

    display();
}
