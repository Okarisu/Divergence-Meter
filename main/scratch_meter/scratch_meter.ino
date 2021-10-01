/*

    MAIN

*/

//inicializace knihoven
#include <Wire.h>
#include <DS3231.h>

//nastavení pinů RTC modulu
int SCLpin = A5;
int SDApin = A4;

bool power = true; //proměnná řídící přívod energie do itronů skrze relé
bool divergence = false; //proměnná řídící, zda je zobrazován čas nebo světová linka
bool scramble = false; //proměnná k zahájení cyklu

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

void loop(){


    if (power){
        digitalWrite(relayOutput, HIGH); //zapnutí itronů

        
            divergenceFce();
        

       

    } else {
        digitalWrite(relayOutput, LOW); //vypnutí itronů
    }

}

/*  !MAIN   */

/*

    DISPLAY

*/

int delayDigitChangeTime = 10; //čas, po který budou jednotlivé itrony zobrazovat číslice


void display()
{

    //pole obsahující proměnné k postupnému spínání mřížek všech itronů
    byte displayArray[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

    byte displayGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

    int displayArrayPosition = 0; //proměnná pro výběr hodnoty z pole a zároveň k řízení následujícího cyklu

    //cyklus, kreý projde všechna čísla uložená v poli displayArray a postupně je zobrazí
    for (displayArrayPosition; displayArrayPosition < 8; displayArrayPosition++)
    {

        //seting latch pins of both shift registers to LOW to be able to write data to them
        digitalWrite(registerSegmentLatchPin, LOW);
        digitalWrite(registerGridLatchPin, LOW);

        //writing data to the shift registers
        shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, displayArray[displayArrayPosition]); //write digit to be displayed to the shift register driving itron segments

        shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, displayGridArray[displayArrayPosition]); //turning on the itron

        //seting latch pins of both shift registers to HIGH to display the digit
        digitalWrite(registerSegmentLatchPin, HIGH);
        digitalWrite(registerGridLatchPin, HIGH);

        //delay to get whole displaying process on certain frequency
        delay(delayDigitChangeTime);
    }
}

/*  !DISPLAY    */

/*

    DIVERGENCE

*/

//databáze číslic a znaků

byte displayDot = B11111110;
byte displayStroke = B11111101;

byte digitsDatabase[] = {
    B00000011, B10011111,
    B00100101, B00001101,
    B10110001, B01001001,
    B01000001, B00011111,
    B00000001, B00001001
};

//list čísel divergencí k zobrazení
byte divergenceDatabase[] = {1048596};


void divergenceFce()
{
    if(scramble){
        scrambleFce();
    }
    

    //divergenceArray[1] = displayDot; //displaying dot on the second itron for whole time

    long firstDigit = random(0,2);
    
}
byte displayArray[] = {};

void scrambleFce(){

    float nSecondsScramble = 5; //čas, po kterýmá trvat prohazování číslic
    int repeatCycle = round(nSecondsScramble*1000/(8*delayDigitChangeTime)); //přibližný počet cyklů potřebných k naplnění délky tvání prohazování. Detaily v dokumentaci. 

    /*
    Getting random number for each itron except of the second one
    and writing it into the display-array.
    Note that random() function returns number from minimum to maximum-1, not maximum - for 9 elements in array (starting from 0) makes it random(0,10).
    */

    for(int i = 0; i < repeatCycle; i++){

    byte displayArray[] = {digitsDatabase[random(0,10)], displayDot, digitsDatabase[random(0,10)], digitsDatabase[random(0,10)], digitsDatabase[random(0,10)], digitsDatabase[random(0,10)], digitsDatabase[random(0,10)], digitsDatabase[random(0,10)]};
    
    display();

    }

    scramble = false;
}

void loadDiv(){

  
  int divergenceValue = divergenceDatabase[random(0,sizeof(divergenceDatabase)+1)];
  int digit;

  for(int i = 7; i >= 2; i--){
      digit = divergenceValue % 10;
      displayArray[i] = divergenceDatabase[digit];
      divergenceValue = divergenceValue / 10;
    }
    displayArray[1] = displayDot;
    digit = divergenceValue % 10;
    displayArray[0] = divergenceDatabase[digit];
  
  }
