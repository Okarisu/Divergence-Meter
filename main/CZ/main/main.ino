//inicializace knihoven
#include <Wire.h>
//#include <DS3231.h>

//nastavení pinů RTC modulu
int SCLpin = A5;
int SDApin = A4;

bool power = false;
bool divergence = false;
bool scramble = false;

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
    pinMode(SCLpin, INPUT);
    pinMode(SDApin, INPUT);

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

        if (divergence)
        {
            divergence();
        }
        else if (!divergence)
        {
            getTime();
        }
    }
    else
    {
        digitalWrite(relayOutput, LOW); //vypnutí itronů
    }
}