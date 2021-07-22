//libraries init
#include <Wire.h>
#include <DS3231.h>

//RTC module pinnout
int SCLpin = A5;
int SDApin = A4;

bool power = true; //Switch variable - when false, nothing is being displayed

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

    /*setting all driving pins to OUTPUT from Arduino board*/
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

    //cycle to go through all digits and display them 
    for (divergenceArrayPosition; divergenceArrayPosition < 8; divergenceArrayPosition++)
    {

        //seting latch pins of both shift registers to LOW to be able to write data to them
        digitalWrite(registerSegmentLatchPin, LOW);
        digitalWrite(registerGridLatchPin, LOW);

        //writing data to the shift registers
        shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, divergenceArray[divergenceArrayPosition]); //write digit to be displayed to the shift register driving itron segments

        shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, divergenceGridArray[divergenceArrayPosition]); //turning on the itron

        //seting latch pins of both shift registers to HIGH to display the digit
        digitalWrite(registerSegmentLatchPin, HIGH);
        digitalWrite(registerGridLatchPin, HIGH);

        //delay to get whole displaying process on certain frequency
        delay(delayNumberChangeTime);
    }
}
