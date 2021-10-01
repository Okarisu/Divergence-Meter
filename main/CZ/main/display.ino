int delayDigitChangeTime = 10; //čas v ms, po který budou jednotlivé itrony zobrazovat číslice

void display()
{
    byte displayArray[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

    byte displayGridArray[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

    int displayArrayPosition = 0;

    //cyklus, kreý projde všechna čísla uložená v poli displayArray a postupně je zobrazí
    for (displayArrayPosition; displayArrayPosition < 8; displayArrayPosition += 1)
    {
        digitalWrite(registerSegmentLatchPin, LOW);
        digitalWrite(registerGridLatchPin, LOW);

        shiftOut(registerSegmentDataPin, registerSegmentClockPin, LSBFIRST, displayArray[displayArrayPosition]);
        shiftOut(registerGridDataPin, registerGridClockPin, LSBFIRST, displayGridArray[displayArrayPosition]);

        digitalWrite(registerSegmentLatchPin, HIGH);
        digitalWrite(registerGridLatchPin, HIGH);

        delay(delayDigitChangeTime);
    }
}
