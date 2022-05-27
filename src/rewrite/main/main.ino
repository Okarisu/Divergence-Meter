// inicializace knihoven
#include <Wire.h>
#include <DS3231.h>

// nastavení pinů RTC modulu
#define RTC_SCLpin A5;
#define RTC_SDApin A4;

// regist řídící segmenty itronů
#define registerSegmentLatchPin ;
#define registerSegmentDataPin ;
#define registerSegmentClockPin ;

// registr řídící mřížky itronů
#define registerGridLatchPin ;
#define registerGridDataPin ;
#define registerGridClockPin ;

#define relayOutputPin ; // pin s připojeným relé k řízení přívodu proudu k itronům

#define powerSwitchPin ;
#define displaySwitchPin ;
#define scrambleSwitchPin ;

public bool power = false;
public bool show_divergence = false;
public bool do_scramble = false;

void setup()
{
    // Nastavení pinů
    pinMode(RTC_SCLpin, INPUT);
    pinMode(RTC_SDApin, INPUT);

    pinMode(registerSegmentLatchPin, OUTPUT);
    pinMode(registerSegmentDataPin, OUTPUT);
    pinMode(registerSegmentClockPin, OUTPUT);

    pinMode(registerGridLatchPin, OUTPUT);
    pinMode(registerGridDataPin, OUTPUT);
    pinMode(registerGridClockPin, OUTPUT);

    pinMode(relayOutputPin, OUTPUT);

    pinMode(powerSwitchPin, INPUT_PULLUP);
    pinMode(displaySwitchPin, INPUT_PULLUP);
    pinMode(scrambleSwitchPin, INPUT_PULLUP);

    //    bluetooth.begin(9600);
}

void loop()
{

    if (power)
    {
        digitalWrite(relayOutputPin, HIGH); // zapnutí itronů

        if (show_divergence)
        {
            divergenceFunction();
        }
        else
        {
            getTimeFunction();
            do_scramble = true;
        }
    }
    else
    {
        digitalWrite(relayOutputPin, LOW); // vypnutí itronů
    }
}
