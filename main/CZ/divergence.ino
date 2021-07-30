/*

Function to assign bytes for shift register array
________________.

*/

//bytes database that divergence function takes data from 

byte displayDot = B11111110;

byte digitsDatabase[] = {
    B00000011, B10011111,
    B00100101, B00001101,
    B10110001, B01001001,
    B01000001, B00011111,
    B00000001, B00001001
};


void divergence()
{
    if(scramble){
        scramble();
    }
    

    //divergenceArray[1] = displayDot; //displaying dot on the second itron for whole time

    long firstDigit = random(0,2);
    
}

void scramble(){

    float nSecondsScramble = 5; //čas, po kterýmá trvat prohazování číslic
    int repeatCycle = round(nSecondsScramble*1000/(8*delayDigitChangeTime)) //přiblížný počet cyklů potřebných k naplnění délky tvání prohazování. Detaily v dokumentaci. 

    /*
    Getting random number for each itron except of the second one
    and writing it into the display-array.
    Note that random() function returns number from minimum to maximum-1, not maximum - for 9 elements in array (starting from 0) makes it random(0,10).
    */

    for(int i = 0; i < repeatCycle; i++){

    divergenceArray[] = {digitsDatabase[random(0,10), displayDot, digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10)]};
    
    display();

    }

    scramble = false;
}