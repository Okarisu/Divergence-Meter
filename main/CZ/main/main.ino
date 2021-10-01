//inicializace knihoven
#include <Wire.h>
//#include <DS3231.h>

//nastavení pinů RTC modulu
int SCLpin = A5;
int SDApin = A4;

bool power = false;
bool show_divergence = false;
bool do_scramble = false;

//regist řídící segmenty itronů
int register_segment_latch_pin;
int register_segment_clock_pin;
int register_segment_data_pin;

//registr řídící mřížky itronů
int register_grid_latch_pin;
int register_grid_clock_pin;
int register_grid_data_pin;

int relay_output; //pin s připojeným relé k zapínání/vypínání přívodu proudu k itronům

void setup()
{
    pinMode(SCLpin, INPUT);
    pinMode(SDApin, INPUT);

    pinMode(register_segment_latch_pin, OUTPUT);
    pinMode(register_segment_clock_pin, OUTPUT);
    pinMode(register_segment_data_pin, OUTPUT);

    pinMode(register_grid_latch_pin, OUTPUT);
    pinMode(register_grid_clock_pin, OUTPUT);
    pinMode(register_grid_data_pin, OUTPUT);

    pinMode(relay_output, OUTPUT);
}

void loop()
{
    if (power)
    {
        digitalWrite(relay_output, HIGH); //zapnutí itronů

        if (show_divergence)
        {
            divergence();
        }
        else
        {
            getTime();
        }
    }
    else
    {
        digitalWrite(relay_output, LOW); //vypnutí itronů
    }
}
