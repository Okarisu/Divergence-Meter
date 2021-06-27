/*

Function to assign specific bytes for shift register array
depending on time sent from RTC.

Switch takes current time from dateTime variable and based on its value,
assigns specific byte to positions of an array.

*/


//variables to drive pins of shift register
byte displayZero = B00000011;
byte displayOne = B10011111;
byte displayTwo = B00100101;
byte displayThree = B00001101;
byte displayFour = B10110001;
byte displayFive = B01001001;
byte displaySix = B01000001;
byte displaySeven = B00011111;
byte displayEight = B00000001;
byte displayNine = B00001001;
byte displayDot = B11111110;


//RTC module variables
DS3231 rtc;
RTCDateTime dateTime;


void getTime(){

    dateTime = rtc.getDateTime();

    //GET HOUR
    if(dateTime.hour <= 9){

        divergenceArray[0] = displayZero; //display 0 on the first itron

        switch(dateTime.hour) {

            case 0:
                divergenceArray[1] = displayZero;
                break;

            case 1:
                divergenceArray[1] = displayOne;
                break;
            
            case 2:
                divergenceArray[1] = displayTwo;
                break;
            
            case 3:
                divergenceArray[1] = displayThree;
                break;

            case 4:
                divergenceArray[1] = displayFour;
                break;
            
            case 5:
                divergenceArray[1] = displayFive;
                break;
            
            case 6:
                divergenceArray[1] = displaySix;
                break;
            
            case 7:
                divergenceArray[1] = displaySeven;
                break;

            case 8:
                divergenceArray[1] = displayEight;
                break;
            
            case 9:
                divergenceArray[1] = displayNine;
                break;
        }
    } else if ((dateTime.hour >= 10) && (dateTime.hour <= 19)){

        divergenceArray[0] = displayOne; //display 1 on the first itron

        switch(dateTime.hour){


            case 10:
                divergenceArray[1] = displayZero;
                break;

            case 11:
                divergenceArray[1] = displayOne;
                break;

            case 12:
                divergenceArray[1] = displayTwo;
                break;

            case 13:
                divergenceArray[1] = displayThree;
                break;

            case 14:
                divergenceArray[1] = displayFour;
                break;

            case 15:
                divergenceArray[1] = displayFive;
                break;

            case 16:
                divergenceArray[1] = displaySix;
                break;

            case 17:
                divergenceArray[1] = displaySeven;
                break;

            case 18:
                divergenceArray[1] = displayEight;
                break;

            case 19:
                divergenceArray[1] = displayNine;
                break;
        }

    } else if ((dateTime.hour >= 20) && (dateTime.hour < 24)){

        divergenceArray[0] = displayTwo; //display 2 on the first itron

        switch(dateTime.hour){

            case 20:
                divergenceArray[1] = displayZero;
                break;

            case 21:
                divergenceArray[1] = displayOne;
                break;

            case 22:
                divergenceArray[1] = displayTwo;
                break;

            case 23:
                divergenceArray[1] = displayThree;
                break;
        }

    }
    //!GET HOUR

    divergenceArray[2] = B11111101; //display '-' on the third itron


    //GET MINUTE
    if(dateTime.minute <= 9){

        divergenceArray[3] = displayZero; //display 0 on the fourth itron

        switch(dateTime.minute) {

            case 0:
                divergenceArray[4] = displayZero;
                break;

            case 1:
                divergenceArray[4] = displayOne;
                break;
            
            case 2:
                divergenceArray[4] = displayTwo;
                break;
            
            case 3:
                divergenceArray[4] = displayThree;
                break;

            case 4:
                divergenceArray[4] = displayFour;
                break;
            
            case 5:
                divergenceArray[4] = displayFive;
                break;
            
            case 6:
                divergenceArray[4] = displaySix;
                break;
            
            case 7:
                divergenceArray[4] = displaySeven;
                break;

            case 8:
                divergenceArray[4] = displayEight;
                break;
            
            case 9:
                divergenceArray[4] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 10) && (dateTime.minute <= 19)){

        divergenceArray[3] = displayOne; //display 1 on the fourth itron

        switch(dateTime.minute){


            case 10:
                divergenceArray[4] = displayZero;
                break;

            case 11:
                divergenceArray[4] = displayOne;
                break;

            case 12:
                divergenceArray[4] = displayTwo;
                break;

            case 13:
                divergenceArray[4] = displayThree;
                break;

            case 14:
                divergenceArray[4] = displayFour;
                break;

            case 15:
                divergenceArray[4] = displayFive;
                break;

            case 16:
                divergenceArray[4] = displaySix;
                break;

            case 17:
                divergenceArray[4] = displaySeven;
                break;

            case 18:
                divergenceArray[4] = displayEight;
                break;

            case 19:
                divergenceArray[4] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 20) && (dateTime.minute <= 29)){

        divergenceArray[3] = displayTwo; //display 2 on the fourth itron

        switch(dateTime.minute){


            case 20:
                divergenceArray[4] = displayZero;
                break;

            case 21:
                divergenceArray[4] = displayOne;
                break;

            case 22:
                divergenceArray[4] = displayTwo;
                break;

            case 23:
                divergenceArray[4] = displayThree;
                break;

            case 24:
                divergenceArray[4] = displayFour;
                break;

            case 25:
                divergenceArray[4] = displayFive;
                break;

            case 26:
                divergenceArray[4] = displaySix;
                break;

            case 27:
                divergenceArray[4] = displaySeven;
                break;

            case 28:
                divergenceArray[4] = displayEight;
                break;

            case 29:
                divergenceArray[4] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 30) && (dateTime.minute <= 39)){

        divergenceArray[3] = displayThree; //display 3 on the fourth itron

        switch(dateTime.minute){


            case 30:
                divergenceArray[4] = displayZero;
                break;

            case 31:
                divergenceArray[4] = displayOne;
                break;

            case 32:
                divergenceArray[4] = displayTwo;
                break;

            case 33:
                divergenceArray[4] = displayThree;
                break;

            case 34:
                divergenceArray[4] = displayFour;
                break;

            case 35:
                divergenceArray[4] = displayFive;
                break;

            case 36:
                divergenceArray[4] = displaySix;
                break;

            case 37:
                divergenceArray[4] = displaySeven;
                break;

            case 38:
                divergenceArray[4] = displayEight;
                break;

            case 39:
                divergenceArray[4] = displayNine;
                break;
        }

    } else if ((dateTime.minute >= 40) && (dateTime.minute <= 49)){

        divergenceArray[3] = displayFour; //display 4 on the fourth itron

        switch(dateTime.minute){


            case 40:
                divergenceArray[4] = displayZero;
                break;

            case 41:
                divergenceArray[4] = displayOne;
                break;

            case 42:
                divergenceArray[4] = displayTwo;
                break;

            case 43:
                divergenceArray[4] = displayThree;
                break;

            case 44:
                divergenceArray[4] = displayFour;
                break;

            case 45:
                divergenceArray[4] = displayFive;
                break;

            case 46:
                divergenceArray[4] = displaySix;
                break;

            case 47:
                divergenceArray[4] = displaySeven;
                break;

            case 48:
                divergenceArray[4] = displayEight;
                break;

            case 49:
                divergenceArray[4] = displayNine;
                break;
        }

    } else if ((dateTime.minute >= 50) && (dateTime.minute <= 59)){

        divergenceArray[3] = displayFive; //display 5 on the fourth itron

        switch(dateTime.minute){


            case 50:
                divergenceArray[4] = displayZero;
                break;

            case 51:
                divergenceArray[4] = displayOne;
                break;

            case 52:
                divergenceArray[4] = displayTwo;
                break;

            case 53:
                divergenceArray[4] = displayThree;
                break;

            case 54:
                divergenceArray[4] = displayFour;
                break;

            case 55:
                divergenceArray[4] = displayFive;
                break;

            case 56:
                divergenceArray[4] = displaySix;
                break;

            case 57:
                divergenceArray[4] = displaySeven;
                break;

            case 58:
                divergenceArray[4] = displayEight;
                break;

            case 59:
                divergenceArray[4] = displayNine;
                break;
        }
    }
    //!GET MINUTE

    divergenceArray[5] = B11111101; //display '-' on the sixth itron


    //GET SECOND
    if(dateTime.second <= 9){

        divergenceArray[6] = displayZero; //display 0 on the seventh itron

        switch(dateTime.second) {

            case 0:
                divergenceArray[7] = displayZero;
                break;

            case 1:
                divergenceArray[7] = displayOne;
                break;
            
            case 2:
                divergenceArray[7] = displayTwo;
                break;
            
            case 3:
                divergenceArray[7] = displayThree;
                break;

            case 4:
                divergenceArray[7] = displayFour;
                break;
            
            case 5:
                divergenceArray[7] = displayFive;
                break;
            
            case 6:
                divergenceArray[7] = displaySix;
                break;
            
            case 7:
                divergenceArray[7] = displaySeven;
                break;

            case 8:
                divergenceArray[7] = displayEight;
                break;
            
            case 9:
                divergenceArray[7] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 10) && (dateTime.second <= 19)){

        divergenceArray[6] = displayOne; //display 1 on the seventh itron

        switch(dateTime.second){


            case 10:
                divergenceArray[7] = displayZero;
                break;

            case 11:
                divergenceArray[7] = displayOne;
                break;

            case 12:
                divergenceArray[7] = displayTwo;
                break;

            case 13:
                divergenceArray[7] = displayThree;
                break;

            case 14:
                divergenceArray[7] = displayFour;
                break;

            case 15:
                divergenceArray[7] = displayFive;
                break;

            case 16:
                divergenceArray[7] = displaySix;
                break;

            case 17:
                divergenceArray[7] = displaySeven;
                break;

            case 18:
                divergenceArray[7] = displayEight;
                break;

            case 19:
                divergenceArray[7] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 20) && (dateTime.second <= 29)){

        divergenceArray[6] = displayTwo; //display 2 on the seventh itron

        switch(dateTime.second){


            case 20:
                divergenceArray[7] = displayZero;
                break;

            case 21:
                divergenceArray[7] = displayOne;
                break;

            case 22:
                divergenceArray[7] = displayTwo;
                break;

            case 23:
                divergenceArray[7] = displayThree;
                break;

            case 24:
                divergenceArray[7] = displayFour;
                break;

            case 25:
                divergenceArray[7] = displayFive;
                break;

            case 26:
                divergenceArray[7] = displaySix;
                break;

            case 27:
                divergenceArray[7] = displaySeven;
                break;

            case 28:
                divergenceArray[7] = displayEight;
                break;

            case 29:
                divergenceArray[7] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 30) && (dateTime.second <= 39)){

        divergenceArray[6] = displayThree; //display 3 on the seventh itron

        switch(dateTime.second){


            case 30:
                divergenceArray[7] = displayZero;
                break;

            case 31:
                divergenceArray[7] = displayOne;
                break;

            case 32:
                divergenceArray[7] = displayTwo;
                break;

            case 33:
                divergenceArray[7] = displayThree;
                break;

            case 34:
                divergenceArray[7] = displayFour;
                break;

            case 35:
                divergenceArray[7] = displayFive;
                break;

            case 36:
                divergenceArray[7] = displaySix;
                break;

            case 37:
                divergenceArray[7] = displaySeven;
                break;

            case 38:
                divergenceArray[7] = displayEight;
                break;

            case 39:
                divergenceArray[7] = displayNine;
                break;
        }

    } else if ((dateTime.second >= 40) && (dateTime.second <= 49)){

        divergenceArray[6] = displayFour; //display 4 on the seventh itron

        switch(dateTime.second){


            case 40:
                divergenceArray[7] = displayZero;
                break;

            case 41:
                divergenceArray[7] = displayOne;
                break;

            case 42:
                divergenceArray[7] = displayTwo;
                break;

            case 43:
                divergenceArray[7] = displayThree;
                break;

            case 44:
                divergenceArray[7] = displayFour;
                break;

            case 45:
                divergenceArray[7] = displayFive;
                break;

            case 46:
                divergenceArray[7] = displaySix;
                break;

            case 47:
                divergenceArray[7] = displaySeven;
                break;

            case 48:
                divergenceArray[7] = displayEight;
                break;

            case 49:
                divergenceArray[7] = displayNine;
                break;
        }

    } else if ((dateTime.second >= 50) && (dateTime.second <= 59)){

        divergenceArray[6] = displayFive; //display 5 on the seventh itron

        switch(dateTime.second){


            case 50:
                divergenceArray[7] = displayZero;
                break;

            case 51:
                divergenceArray[7] = displayOne;
                break;

            case 52:
                divergenceArray[7] = displayTwo;
                break;

            case 53:
                divergenceArray[7] = displayThree;
                break;

            case 54:
                divergenceArray[7] = displayFour;
                break;

            case 55:
                divergenceArray[7] = displayFive;
                break;

            case 56:
                divergenceArray[7] = displaySix;
                break;

            case 57:
                divergenceArray[7] = displaySeven;
                break;

            case 58:
                divergenceArray[7] = displayEight;
                break;

            case 59:
                divergenceArray[7] = displayNine;
                break;
        }
    }
    //!GET SECOND

}