int digitChangeTimeDelay = 10; //čas v ms, po který budou jednotlivé itrony zobrazovat číslice

byte display_array[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

void displayFunction()
{

    //byte powerGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

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

    digitalWrite(registerSegmentLatchPin, LOW);
    digitalWrite(registerGridLatchPin, LOW);

    shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, display_array[0]);
    shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, B00000000);

    digitalWrite(registerSegmentLatchPin, HIGH);
    digitalWrite(registerGridLatchPin, HIGH);

    delay(2000);

    digitalWrite(registerSegmentLatchPin, LOW);
    digitalWrite(registerGridLatchPin, LOW);

    shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, display_array[1]);
    shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, B00000000);

    digitalWrite(registerSegmentLatchPin, HIGH);
    digitalWrite(registerGridLatchPin, HIGH);
}
