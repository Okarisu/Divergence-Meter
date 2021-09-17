//inicializace knihoven
#include <Wire.h>
#include <DS3231.h>

/*
| PROMĚNNÉ |
*/

//nastavení pinů RTC modulu
int SCLpin = A5;
int SDApin = A4;

bool power = true;       //proměnná řídící přívod energie do itronů skrze relé
bool divergence = false; //proměnná řídící, zda je zobrazován čas nebo světová linka
bool scramble = false;   //proměnná k zahájení cyklu

/*nastavení pinů posuvných registrů*/

//regist řídící segmenty itronů
int registerSegmentLatchPin;
int registerSegmentClockPin;
int registerSegmentDataPin;

//registr řídící mřížky itronů
int registerGridLatchPin;
int registerGridClockPin;
int registerGridDataPin;

int relayOutput; //pin s připojeným relé k zapínání/vypínání přívodu proudu k itronům

void setup()
{

    /*nastavení všech potřebných pinů na OUTPUT*/

    pinMode(registerSegmentLatchPin, OUTPUT);
    pinMode(registerSegmentClockPin, OUTPUT);
    pinMode(registerSegmentDataPin, OUTPUT);

    pinMode(registerGridLatchPin, OUTPUT);
    pinMode(registerGridClockPin, OUTPUT);
    pinMode(registerGridDataPin, OUTPUT);

    pinMode(relayOutput, OUTPUT);
}

void loop()
{

    if (power)
    {
        digitalWrite(relayOutput, HIGH); //zapnutí itronů

        getTime(); //funkce hodin
    }
    else
    {
        digitalWrite(relayOutput, LOW); //vypnutí itronů
    }
}

int delayDigitChangeTime = 10; //čas, po který budou jednotlivé itrony zobrazovat číslice v ms

byte displayArray[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

void display()
{

    //pole obsahující proměnné k postupnému spínání mřížek všech itronů

    byte displayGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

    int displayArrayPosition = 0; //proměnná pro výběr hodnoty z pole a zároveň k řízení následujícího cyklu

    //cyklus, který projde všechna čísla uložená v poli displayArray a postupně je zobrazí
    for (displayArrayPosition; displayArrayPosition < 8; displayArrayPosition++)
    {

        //nastavení prostě aby to fungovalo more už ma to sere jebat na to pomoc zachraňte mě chce se mi brečet a umřít v náručí huňaté kočky nebo já fakt nevím už mi hrabe prcat na to celý
        digitalWrite(registerSegmentLatchPin, LOW);
        digitalWrite(registerGridLatchPin, LOW);

        //zápis dat do posuvných registrů
        shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, displayArray[displayArrayPosition]); //write digit to be displayed to the shift register driving itron segments

        shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, displayGridArray[displayArrayPosition]); //zapnutí itronu

        //seting latch pins of both shift registers to HIGH to display the digit
        digitalWrite(registerSegmentLatchPin, HIGH);
        digitalWrite(registerGridLatchPin, HIGH);

        //delay to get whole displaying process on certain frequency
        delay(delayDigitChangeTime);
    }
}


//RTC module variables
DS3231 rtc;
RTCDateTime dateTime;

int hours;
int minutes;
int seconds;

int hoursOne;
int hoursTwo;
int minutesOne;
int minutesTwo;
int secondsOne;
int secondsTwo;

void getTime()
{

    //bytes database that getTime function takes data from
    byte displayStroke = B11111101;

    byte timeDatabase[] = {

        B00000011, B10011111,
        B00100101, B00001101,
        B10110001, B01001001,
        B01000001, B00011111,
        B00000001, B00001001

    };

    dateTime = rtc.getDateTime(); //proměnná s reálným časem z RTC modulu

    /*převedení proměnných na kratší pohodlnější názvy*/

    hours = dateTime.hour;
    minutes = dateTime.minute;
    seconds = dateTime.second;

    /*získání jednotlivých číslic k zobrazení*/

    hoursOne = hours / 10; //první číslice hodin
    hoursTwo = hours % 10; //druhá číslice hodin

    minutesOne = minutes / 10; //první číslice minut
    minutesTwo = minutes % 10; //druhá číslice minut

    secondsOne = seconds / 10; //první číslice sekund
    secondsTwo = seconds % 10; //druhá číslice sekund

    displayArray[] = {timeDatabase[hoursOne], timeDatabase[hoursTwo], displayStroke, timeDatabase[minutesOne], timeDatabase[minutesTwo], displayStroke, timeDatabase[secondsOne], timeDatabase[secondsTwo]};

    display();
}