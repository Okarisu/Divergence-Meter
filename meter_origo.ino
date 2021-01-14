#include "LedControl.h"

/*
   pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
*/

LedControl lc = LedControl(12, 11, 10, 1);


unsigned long delaytime = 500;

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}


void change() {

  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 0, false);
  lc.setDigit(0, 4, 0, false);
  lc.setDigit(0, 3, 0, false);
  lc.setDigit(0, 2, 0, false);
  lc.setDigit(0, 1, 0, false);
  lc.setDigit(0, 0, 0, false);

}

void num1() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 5, false);
  lc.setDigit(0, 4, 7, false);
  lc.setDigit(0, 3, 1, false);
  lc.setDigit(0, 2, 0, false);
  lc.setDigit(0, 1, 2, false);
  lc.setDigit(0, 0, 4, false);


}




void num2() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 5, false);
  lc.setDigit(0, 4, 7, false);
  lc.setDigit(0, 3, 1, false);
  lc.setDigit(0, 2, 0, false);
  lc.setDigit(0, 1, 1, false);
  lc.setDigit(0, 0, 5, false);


}

void num3() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 5, false);
  lc.setDigit(0, 4, 2, false);
  lc.setDigit(0, 3, 3, false);
  lc.setDigit(0, 2, 2, false);
  lc.setDigit(0, 1, 9, false);
  lc.setDigit(0, 0, 9, false);


}

void num4() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 4, false);
  lc.setDigit(0, 4, 5, false);
  lc.setDigit(0, 3, 6, false);
  lc.setDigit(0, 2, 9, false);
  lc.setDigit(0, 1, 0, false);
  lc.setDigit(0, 0, 3, false);


}

void num5() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 4, false);
  lc.setDigit(0, 4, 0, false);
  lc.setDigit(0, 3, 9, false);
  lc.setDigit(0, 2, 4, false);
  lc.setDigit(0, 1, 2, false);
  lc.setDigit(0, 0, 0, false);


}

void num6() {


  lc.setDigit(0, 7, 0, false);
  lc.setChar(0, 6, '.', false);
  lc.setDigit(0, 5, 3, false);
  lc.setDigit(0, 4, 3, false);
  lc.setDigit(0, 3, 7, false);
  lc.setDigit(0, 2, 1, false);
  lc.setDigit(0, 1, 8, false);
  lc.setDigit(0, 0, 7, false);


}

void zobraz_cislo_0(){
lc.setDigit(0, 7, 0, false);

}

void loop() {
  num1();
  delay(1000);
  num2();
  delay(1000);
  num3();
  delay(1000);
  num4();
  delay(1000);
  num5();
  delay(1000);
  num6();
  delay(1000);
}