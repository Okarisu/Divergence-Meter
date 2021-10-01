byte displayDot = B11111110;
byte divergence_database[] = {};

byte digits_database[] = {
    B00000011, B10011111,
    B00100101, B00001101,
    B10110001, B01001001,
    B01000001, B00011111,
    B00000001, B00001001};

void divergence()
{
    if (do_scramble)
    {
        scramble();
    }

    load_divergence();
}

void scramble()
{

    float nSecondsScramble = 5; //čas, po kterýmá trvat prohazování číslic
    int repeatCycle = round(nSecondsScramble * 1000 / (8 * delayDigitChangeTime)); //přibližný počet cyklů potřebných k naplnění délky tvání prohazování. Detaily v dokumentaci.

    for (int i = 0; i < repeatCycle; i++)
    {
    display_array[] = {digits_database[random(0,10)], displayDot, digits_database[random(0,10)], digits_database[random(0,10)], digits_database[random(0,10)], digits_database[random(0,10)], digits_database[random(0,10)], digits_database[random(0,10)]};
    display();
    }

    scramble = false;
}

void load_divergence()
{

    int divergenceValue = divergence_database[random(0, divergence_database.length() + 1)];
    int digit;

    for (int i = 7; i >= 0; i -= 1)
    {
        digit = divergenceValue % 10;
        display_array[i] = divergence_database[digit];
        divergenceValue = divergenceValue / 10;
    }
}
