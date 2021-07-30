//inicializace knihoven
#include <Wire.h>
#include <DS3231.h>


/*
| PROMĚNNÉ |
*/

//nastavení pinů RTC modulu
int SCLpin = A5;
int SDApin = A4;

bool power = true; //proměnná řídící přívod energie do itronů skrze relé
bool divergence = false; //proměnná řídící, zda je zobrazován čas nebo světová linka
bool scramble = false; //proměnnák zahájení cyklu 

/*nastavení pinů posuvných registrů*/

//regist řídící segmenty itronů
int registerSegmentLatchPin;
int registerSegmentClockPin;
int registerSegmentDataPin;

//registr řídící mřížky itronů
int registerGridLatchPin;
int registerGridClockPin;
int registerGridDataPin;


byte divergenceArray[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

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

void loop(){


    if (power){
        digitalWrite(relayOutput, HIGH); //zapnutí itronů

        if(divergence){
            divergence();
        } else if (!divergence){
            getTime();
        } 

       

    } else {
        digitalWrite(relayOutput, LOW); //vypnutí itronů
    }

}
