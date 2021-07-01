/*

Function to assign specific bytes for shift register array
depending on time sent from RTC.

Switch takes current time from dateTime variable and based on its value,
assigns specific byte to positions of an array.

*/


//variables to drive pins of shift register
byte displayZero = B00000011;
byte displayOne = B10011111;
byte displayTwo = B00100101;
byte displayThree = B00001101;
byte displayFour = B10110001;
byte displayFive = B01001001;
byte displaySix = B01000001;
byte displaySeven = B00011111;
byte displayEight = B00000001;
byte displayNine = B00001001;
byte displayDot = B11111110;


byte timeDatabase[] = {

    
}

//RTC module variables
DS3231 rtc;
RTCDateTime dateTime;


int hours;
int minutes;
int seconds;

int hoursF;
int hoursS;
int minutesF;
int minutelS;
int secondsF;
int secondsS;


void getTime(){

    dateTime = rtc.getDateTime();

    hours = dateTime.hour;
    minutes = dateTime.minute;
    second = dateTime.second;

    hoursF = hours/10;
    hoursS = hours%10;

    minutesF = minutes/10;
    minutelS = minutes%10;

    secondsF = seconds/10;
    secondsS = seconds%10;

}