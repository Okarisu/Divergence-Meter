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
    divergenceArray[1] = displayDot; //displaying dot on the second itron for whole time

    scramble();
    long firstDigit = random(0,2);
    
}

void scramble(){

    float nSecondsScramble = 5; //Circa how many seconds should scramble last
    int repeatCycle = round(nSecondsScramble*1000/80) //How many cycles will it take to scramble. For details see readme.

    /*
    Getting random number for each itron except of the second one
    and writing it into the display-array.
    Note that random() function returns number from minimum to maximum-1, not maximum! For 9 elements in array (starting from 0)ka makes it random(0,10).
    */

    for(int i = 0; i < repeatCycle; i++){

    divergenceArray[] = {digitsDatabase[random(0,10), displayDot, digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10), digitsDatabase[random(0,10)];
    
    }
}