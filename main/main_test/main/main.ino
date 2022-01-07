//inicializace knihoven
#include <Wire.h>
//#include <DS3231.h>

//nastavení pinů RTC modulu
//#define SCLpin = A5;
//#define SDApin = A4;

//regist řídící segmenty itronů
#define registerSegmentLatchPin 7 //RCLK 12
#define registerSegmentDataPin 8 //SRCLK 11
#define registerSegmentClockPin 6 //Data 14

//registr řídící mřížky itronů
#define registerGridLatchPin 3
#define registerGridDataPin 4
#define registerGridClockPin 2

//#define relayOutputPin ; //pin s připojeným relé k zapínání/vypínání přívodu proudu k itronům

//#define powerSwitchPin ;
//#define displaySwitchPin ;
//#define scrambleSwitchPin ;

void setup()
{
  /*
    pinMode(SCLpin, INPUT);
    pinMode(SDApin, INPUT);
  */
  pinMode(registerSegmentLatchPin, OUTPUT);
  pinMode(registerSegmentDataPin, OUTPUT);
  pinMode(registerSegmentClockPin, OUTPUT);

  pinMode(registerGridLatchPin, OUTPUT);
  pinMode(registerGridDataPin, OUTPUT);
  pinMode(registerGridClockPin, OUTPUT);
  /*
      pinMode(relayOutputPin, OUTPUT);

      pinMode(powerSwitchPin, INPUT_PULLUP);
      pinMode(displaySwitchPin, INPUT_PULLUP);
      pinMode(scrambleSwitchPin, INPUT_PULLUP);
  */
  //    bluetooth.begin(9600);
}

void loop()
{

  divergenceFunction();

}
