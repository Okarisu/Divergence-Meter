//libraries init
#include <Wire.h>
#include <DS3231.h>

//RTC module pinnout
int SCLpin = A5;
int SDApin = A4;


bool power = false;

bool divergence = false; //When true, divergence value is displayed. When false, current time is displayed.

//segments shift register pinnout
int registerSegmentLatchPin;
int registerSegmentClockPin;
int registerSegmentDataPin;

//grids shift register pinnout
int registerGridLatchPin;
int registerGridClockPin;
int registerGridDataPin;

/*arrays with bytes to write through registers*/

byte divergenceArray[8]; //array with elements to display numbers

//array with elements to power itron grids; each array element represents one itron powered on
byte divergenceGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

int divergenceArrayPosition = 0; //variable for array element selection

int delayNumberChangeTime = 10; //delay in ms to switch between powering itrons

void setup()
{
    pinMode(registerSegmentLatchPin, OUTPUT);
    pinMode(registerSegmentClockPin, OUTPUT);
    pinMode(registerSegmentDataPin, OUTPUT);

    pinMode(registerGridLatchPin, OUTPUT);
    pinMode(registerGridClockPin, OUTPUT);
    pinMode(registerGridDataPin, OUTPUT);
}

void loop(){
    if(divergence){
        divergence();
    } else if (!divergence){
        getTime();
    }

    display();
}

void display()
{
    for (divergenceArrayPosition; divergenceArrayPosition < 8; divergenceArrayPosition++)
    {

        digitalWrite(registerSegmentLatchPin, LOW);
        digitalWrite(registerGridLatchPin, LOW);

        shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, divergenceArray[divergenceArrayPosition]);
        shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, divergenceGridArray[divergenceArrayPosition]);

        digitalWrite(registerSegmentLatchPin, HIGH);
        digitalWrite(registerGridLatchPin, HIGH);

        delay(delayNumberChangeTime);
    }
}
