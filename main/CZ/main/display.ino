//public variables
int delayDigitChangeTime = 10; //čas v ms, po který budou jednotlivé itrony zobrazovat číslice

byte display_array[8]; //pole obsahující číslice k zápisu do registu segmentů a následnému zobrazení

void display()
{
    

    byte power_grid_array[] = {B01111111, B10111111, B11011111, B11101111, B11110111, B11111011, B11111101, B11111110};

    int display_array_position = 0;

    //cyklus, kreý projde všechna čísla uložená v poli displayArray a postupně je zobrazí
    for (display_array_position; display_array_position < 8; display_array_position += 1)
    {
        digitalWrite(register_segment_latch_pin, LOW);
        digitalWrite(register_grid_latch_pin, LOW);

        shiftOut(register_segment_data_pin, register_segment_clock_pin, LSBFIRST, display_array[display_array_position]);
        shiftOut(register_grid_data_pin, register_grid_clock_pin, LSBFIRST, power_grid_array[display_array_position]);

        digitalWrite(register_segment_latch_pin, HIGH);
        digitalWrite(register_grid_latch_pin, HIGH);

        delay(delayDigitChangeTime);
    }
}
