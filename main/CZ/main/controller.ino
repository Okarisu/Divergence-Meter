#include <SoftwareYŚerial.h>

#define RX;
#define TX;

SoftwareSerial bluetooth(TX, RX);

void switches(){

casomira = millis();
  */
  while(!digitalRead(3))
  {
    dobaStisku = millis()-casomira;
  }
  if(dobaStisku >= limit)
  {
    svitit = !svitit;
    dobaStisku = 0;
  }
/*

}

void bluetooth()
{

    byte bluetooth_input;

    if (bluetooth.available() > 0) {
    
        bluetooth_input = bluetooth.read();


        switch (bluetooth_input){

                //power
                case 'pwr':
                    power = !power;
                    break;
                case 'on':
                    power = true;
                    break;
                case 'off':
                    power = false;
                    break;

                //div || time
                case 'div':
                    show_divergence = true;
                    break;
                case 'time':
                    show_divergence = false;
                    break;

                //scramble
                case 'scramble':
                    do_scramble = true;
                    break;




                default:
                    bluetooth.println("Illegal argument"); 
                
        }
    }
    delay(10);
}