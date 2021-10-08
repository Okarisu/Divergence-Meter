byte dot_byte = B11111110;
int divergence_database[] = {10000000, 1234567};

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
        scrambleFce();
    }

    load_divergence();
}

void scrambleFce()
{

    int n_seconds_scramble = 5;                                                          //čas, po kterýmá trvat prohazování číslic
    int repeat_cycle = round(n_seconds_scramble * 1000 / (8 * digit_change_time_delay)); //přibližný počet cyklů potřebných k naplnění délky tvání prohazování. Detaily v dokumentaci.

    for (int i = 0; i < repeat_cycle; i++)
    {
        display_array[0] = {digits_database[random(0, 10)]};
        display_array[1] = {dot_byte};
        display_array[2] = {digits_database[random(0, 10)]};
        display_array[3] = {digits_database[random(0, 10)]};
        display_array[4] = {digits_database[random(0, 10)]};
        display_array[5] = {digits_database[random(0, 10)]};
        display_array[6] = {digits_database[random(0, 10)]};
        display_array[7] = {digits_database[random(0, 10)]};
        display();
    }

    do_scramble = false;
}

void load_divergence()
{

    // int divergenceValue = divergence_database[random(0, divergence_database.length())];
    int divergenceValue = divergence_database[random(0, sizeof(divergence_database))];
    int digit;

    for (int i = 7; i >= 0; i -= 1)
    {
        digit = divergenceValue % 10;
        display_array[i] = digits_database[digit];
        divergenceValue = divergenceValue / 10;
    }
}
