/*
Function to assign specific bytes for shift register array
depending on time sent from RTC.
*/

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

    //bytes database that getTime function takes data from 
    byte displayStroke = B11111101;

    byte timeDatabase[] = {

    B00000011, B10011111,
    B00100101, B00001101,
    B10110001, B01001001,
    B01000001, B00011111,
    B00000001, B00001001

    };


    dateTime = rtc.getDateTime(); //variable containing current time from RTC module

    hours = dateTime.hour;
    minutes = dateTime.minute;
    seconds = dateTime.second;

    /*getting separate time numbers to display each of them on itrons*/

    hoursF = hours/10; //first digit of hours
    hoursS = hours%10; //second digit of hours

    minutesF = minutes/10;
    minutesS = minutes%10;

    secondsF = seconds/10;
    secondsS = seconds%10;

    divergenceArray[] = {timeDatabase[hoursF], timeDatabase[hoursS], displayStroke, timeDatabase[minutesF], timeDatabase[minutesS], displayStroke, timeDatabase[secondsF], timeDatabase[secondsS]};

    display();
}