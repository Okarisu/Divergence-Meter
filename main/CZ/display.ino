int delayDigitChangeTime = 10; //čas, po který budou jednotlivé itrony zobrazovat číslice


void display()
{

    //pole obsahující proměnné k postupnému spínání mřížek všech itronů
    byte divergenceGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

    int divergenceArrayPosition = 0; //proměnná pro výběr hodnoty z pole a zároveň k řízení následujícího cyklu

    //cyklus, kreý projde všechna čísla uložená v poli divergenceArray a postupně je zobrazí
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
        delay(delayDigitChangeTime);
    }
}
