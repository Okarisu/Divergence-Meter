//inicializace knihoven
#include <Wire.h>
//#include <DS3231.h>

//nastavení pinů RTC modulu
#define SCLpin = A5;
#define SDApin = A4;

//regist řídící segmenty itronů
#define register_segment_latch_pin ;
#define register_segment_clock_pin ;
#define register_segment_data_pin ;

//registr řídící mřížky itronů
#define register_grid_latch_pin ;
#define register_grid_clock_pin ;
#define register_grid_data_pin ;

#define relay_output_pin ; //pin s připojeným relé k zapínání/vypínání přívodu proudu k itronům

#define power_switch_pin ;
#define display_switch_pin ;
#define scramble_switch_pin ;

bool power = false;
bool show_divergence = false;
bool do_scramble = false;

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

    pinMode(relay_output_pin, OUTPUT);

    pinMode(power_switch_pin, INPUT_PULLUP);
    pinMode(display_switch_pin, INPUT_PULLUP);
    pinMode(scramble_switch_pin, INPUT_PULLUP);

    //    bluetooth.begin(9600);
}

void loop()
{
    if (power)
    {
        digitalWrite(relay_output_pin, HIGH); //zapnutí itronů

        if (show_divergence)
        {
            divergence();
        }
        else
        {
            getTime();
            do_scramble = true;
        }
    }
    else
    {
        digitalWrite(relay_output_pin, LOW); //vypnutí itronů
    }
}
