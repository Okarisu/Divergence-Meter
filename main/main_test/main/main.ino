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
  byte display_array[] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111}; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

  byte powerGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

  //int displayArrayPosition = 0;

  //cyklus, který projde všechna čísla uložená v poli displayArray a postupně je zobrazí
  /* for (displayArrayPosition; displayArrayPosition < 8; displayArrayPosition += 1)
    {
      digitalWrite(registerSegmentLatchPin, LOW);
      digitalWrite(registerGridLatchPin, LOW);

      shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, display_array[displayArrayPosition]);
      shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, powerGridArray[displayArrayPosition]);

      digitalWrite(registerSegmentLatchPin, HIGH);
      digitalWrite(registerGridLatchPin, HIGH);

      delay(digitChangeTimeDelay);
    }*/

  for (int i = 0; i <= 7; i++) {

    digitalWrite(registerSegmentLatchPin, LOW);
    digitalWrite(registerGridLatchPin, LOW);

    shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, display_array[i]);
    shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, powerGridArray[i]);

    digitalWrite(registerSegmentLatchPin, HIGH);
    digitalWrite(registerGridLatchPin, HIGH);

    delay(10);

  }

}
