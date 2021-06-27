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
                divergenceArray[2] = displayZero;
                break;

            case 1:
                divergenceArray[2] = displayOne;
                break;
            
            case 2:
                divergenceArray[2] = displayTwo;
                break;
            
            case 3:
                divergenceArray[2] = displayThree;
                break;

            case 4:
                divergenceArray[2] = displayFour;
                break;
            
            case 5:
                divergenceArray[2] = displayFive;
                break;
            
            case 6:
                divergenceArray[2] = displaySix;
                break;
            
            case 7:
                divergenceArray[2] = displaySeven;
                break;

            case 8:
                divergenceArray[2] = displayEight;
                break;
            
            case 9:
                divergenceArray[2] = displayNine;
                break;
        }
    } else if ((dateTime.hour >= 10) && (dateTime.hour <= 19)){

        divergenceArray[0] = displayOne; //display 1 on the first itron

        switch(dateTime.hour){


            case 10:
                divergenceArray[2] = displayZero;
                break;

            case 11:
                divergenceArray[2] = displayOne;
                break;

            case 12:
                divergenceArray[2] = displayTwo;
                break;

            case 13:
                divergenceArray[2] = displayThree;
                break;

            case 14:
                divergenceArray[2] = displayFour;
                break;

            case 15:
                divergenceArray[2] = displayFive;
                break;

            case 16:
                divergenceArray[2] = displaySix;
                break;

            case 17:
                divergenceArray[2] = displaySeven;
                break;

            case 18:
                divergenceArray[2] = displayEight;
                break;

            case 19:
                divergenceArray[2] = displayNine;
                break;
        }

    } else if ((dateTime.hour >= 20) && (dateTime.hour < 24)){

        divergenceArray[0] = displayTwo; //display 2 on the first itron

        switch(dateTime.hour){

            case 20:
                divergenceArray[2] = displayZero;
                break;

            case 21:
                divergenceArray[2] = displayOne;
                break;

            case 22:
                divergenceArray[2] = displayTwo;
                break;

            case 23:
                divergenceArray[2] = displayThree;
                break;
        }

    }
    //!GET HOUR

    divergenceArray[4] = B11111101; //display '-' on the third itron


    //GET MINUTE
    if(dateTime.minute <= 9){

        divergenceArray[6] = displayZero; //display 0 on the fourth itron

        switch(dateTime.minute) {

            case 0:
                divergenceArray[8] = displayZero;
                break;

            case 1:
                divergenceArray[8] = displayOne;
                break;
            
            case 2:
                divergenceArray[8] = displayTwo;
                break;
            
            case 3:
                divergenceArray[8] = displayThree;
                break;

            case 4:
                divergenceArray[8] = displayFour;
                break;
            
            case 5:
                divergenceArray[8] = displayFive;
                break;
            
            case 6:
                divergenceArray[8] = displaySix;
                break;
            
            case 7:
                divergenceArray[8] = displaySeven;
                break;

            case 8:
                divergenceArray[8] = displayEight;
                break;
            
            case 9:
                divergenceArray[8] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 10) && (dateTime.minute <= 19)){

        divergenceArray[6] = displayOne; //display 1 on the fourth itron

        switch(dateTime.minute){


            case 10:
                divergenceArray[8] = displayZero;
                break;

            case 11:
                divergenceArray[8] = displayOne;
                break;

            case 12:
                divergenceArray[8] = displayTwo;
                break;

            case 13:
                divergenceArray[8] = displayThree;
                break;

            case 14:
                divergenceArray[8] = displayFour;
                break;

            case 15:
                divergenceArray[8] = displayFive;
                break;

            case 16:
                divergenceArray[8] = displaySix;
                break;

            case 17:
                divergenceArray[8] = displaySeven;
                break;

            case 18:
                divergenceArray[8] = displayEight;
                break;

            case 19:
                divergenceArray[8] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 20) && (dateTime.minute <= 29)){

        divergenceArray[6] = displayTwo; //display 2 on the fourth itron

        switch(dateTime.minute){


            case 20:
                divergenceArray[8] = displayZero;
                break;

            case 21:
                divergenceArray[8] = displayOne;
                break;

            case 22:
                divergenceArray[8] = displayTwo;
                break;

            case 23:
                divergenceArray[8] = displayThree;
                break;

            case 24:
                divergenceArray[8] = displayFour;
                break;

            case 25:
                divergenceArray[8] = displayFive;
                break;

            case 26:
                divergenceArray[8] = displaySix;
                break;

            case 27:
                divergenceArray[8] = displaySeven;
                break;

            case 28:
                divergenceArray[8] = displayEight;
                break;

            case 29:
                divergenceArray[8] = displayNine;
                break;
        }
    
    } else if ((dateTime.minute >= 30) && (dateTime.minute <= 39)){

        divergenceArray[6] = displayThree; //display 3 on the fourth itron

        switch(dateTime.minute){


            case 30:
                divergenceArray[8] = displayZero;
                break;

            case 31:
                divergenceArray[8] = displayOne;
                break;

            case 32:
                divergenceArray[8] = displayTwo;
                break;

            case 33:
                divergenceArray[8] = displayThree;
                break;

            case 34:
                divergenceArray[8] = displayFour;
                break;

            case 35:
                divergenceArray[8] = displayFive;
                break;

            case 36:
                divergenceArray[8] = displaySix;
                break;

            case 37:
                divergenceArray[8] = displaySeven;
                break;

            case 38:
                divergenceArray[8] = displayEight;
                break;

            case 39:
                divergenceArray[8] = displayNine;
                break;
        }

    } else if ((dateTime.minute >= 40) && (dateTime.minute <= 49)){

        divergenceArray[6] = displayFour; //display 4 on the fourth itron

        switch(dateTime.minute){


            case 40:
                divergenceArray[8] = displayZero;
                break;

            case 41:
                divergenceArray[8] = displayOne;
                break;

            case 42:
                divergenceArray[8] = displayTwo;
                break;

            case 43:
                divergenceArray[8] = displayThree;
                break;

            case 44:
                divergenceArray[8] = displayFour;
                break;

            case 45:
                divergenceArray[8] = displayFive;
                break;

            case 46:
                divergenceArray[8] = displaySix;
                break;

            case 47:
                divergenceArray[8] = displaySeven;
                break;

            case 48:
                divergenceArray[8] = displayEight;
                break;

            case 49:
                divergenceArray[8] = displayNine;
                break;
        }

    } else if ((dateTime.minute >= 50) && (dateTime.minute <= 59)){

        divergenceArray[6] = displayFive; //display 5 on the fourth itron

        switch(dateTime.minute){


            case 50:
                divergenceArray[8] = displayZero;
                break;

            case 51:
                divergenceArray[8] = displayOne;
                break;

            case 52:
                divergenceArray[8] = displayTwo;
                break;

            case 53:
                divergenceArray[8] = displayThree;
                break;

            case 54:
                divergenceArray[8] = displayFour;
                break;

            case 55:
                divergenceArray[8] = displayFive;
                break;

            case 56:
                divergenceArray[8] = displaySix;
                break;

            case 57:
                divergenceArray[8] = displaySeven;
                break;

            case 58:
                divergenceArray[8] = displayEight;
                break;

            case 59:
                divergenceArray[8] = displayNine;
                break;
        }
    }
    //!GET MINUTE

    divergenceArray[10] = B11111101; //display '-' on the sixth itron


    //GET SECOND
    if(dateTime.second <= 9){

        divergenceArray[12] = displayZero; //display 0 on the seventh itron

        switch(dateTime.second) {

            case 0:
                divergenceArray[14] = displayZero;
                break;

            case 1:
                divergenceArray[14] = displayOne;
                break;
            
            case 2:
                divergenceArray[14] = displayTwo;
                break;
            
            case 3:
                divergenceArray[14] = displayThree;
                break;

            case 4:
                divergenceArray[14] = displayFour;
                break;
            
            case 5:
                divergenceArray[14] = displayFive;
                break;
            
            case 6:
                divergenceArray[14] = displaySix;
                break;
            
            case 7:
                divergenceArray[14] = displaySeven;
                break;

            case 8:
                divergenceArray[14] = displayEight;
                break;
            
            case 9:
                divergenceArray[14] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 10) && (dateTime.second <= 19)){

        divergenceArray[6] = displayOne; //display 1 on the seventh itron

        switch(dateTime.second){


            case 10:
                divergenceArray[14] = displayZero;
                break;

            case 11:
                divergenceArray[14] = displayOne;
                break;

            case 12:
                divergenceArray[14] = displayTwo;
                break;

            case 13:
                divergenceArray[14] = displayThree;
                break;

            case 14:
                divergenceArray[14] = displayFour;
                break;

            case 15:
                divergenceArray[14] = displayFive;
                break;

            case 16:
                divergenceArray[14] = displaySix;
                break;

            case 17:
                divergenceArray[14] = displaySeven;
                break;

            case 18:
                divergenceArray[14] = displayEight;
                break;

            case 19:
                divergenceArray[14] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 20) && (dateTime.second <= 29)){

        divergenceArray[6] = displayTwo; //display 2 on the seventh itron

        switch(dateTime.second){


            case 20:
                divergenceArray[14] = displayZero;
                break;

            case 21:
                divergenceArray[14] = displayOne;
                break;

            case 22:
                divergenceArray[14] = displayTwo;
                break;

            case 23:
                divergenceArray[14] = displayThree;
                break;

            case 24:
                divergenceArray[14] = displayFour;
                break;

            case 25:
                divergenceArray[14] = displayFive;
                break;

            case 26:
                divergenceArray[14] = displaySix;
                break;

            case 27:
                divergenceArray[14] = displaySeven;
                break;

            case 28:
                divergenceArray[14] = displayEight;
                break;

            case 29:
                divergenceArray[14] = displayNine;
                break;
        }
    
    } else if ((dateTime.second >= 30) && (dateTime.second <= 39)){

        divergenceArray[6] = displayThree; //display 3 on the seventh itron

        switch(dateTime.second){


            case 30:
                divergenceArray[14] = displayZero;
                break;

            case 31:
                divergenceArray[14] = displayOne;
                break;

            case 32:
                divergenceArray[14] = displayTwo;
                break;

            case 33:
                divergenceArray[14] = displayThree;
                break;

            case 34:
                divergenceArray[14] = displayFour;
                break;

            case 35:
                divergenceArray[14] = displayFive;
                break;

            case 36:
                divergenceArray[14] = displaySix;
                break;

            case 37:
                divergenceArray[14] = displaySeven;
                break;

            case 38:
                divergenceArray[14] = displayEight;
                break;

            case 39:
                divergenceArray[14] = displayNine;
                break;
        }

    } else if ((dateTime.second >= 40) && (dateTime.second <= 49)){

        divergenceArray[6] = displayFour; //display 4 on the seventh itron

        switch(dateTime.second){


            case 40:
                divergenceArray[14] = displayZero;
                break;

            case 41:
                divergenceArray[14] = displayOne;
                break;

            case 42:
                divergenceArray[14] = displayTwo;
                break;

            case 43:
                divergenceArray[14] = displayThree;
                break;

            case 44:
                divergenceArray[14] = displayFour;
                break;

            case 45:
                divergenceArray[14] = displayFive;
                break;

            case 46:
                divergenceArray[14] = displaySix;
                break;

            case 47:
                divergenceArray[14] = displaySeven;
                break;

            case 48:
                divergenceArray[14] = displayEight;
                break;

            case 49:
                divergenceArray[14] = displayNine;
                break;
        }

    } else if ((dateTime.second >= 50) && (dateTime.second <= 59)){

        divergenceArray[6] = displayFive; //display 5 on the seventh itron

        switch(dateTime.second){


            case 50:
                divergenceArray[14] = displayZero;
                break;

            case 51:
                divergenceArray[14] = displayOne;
                break;

            case 52:
                divergenceArray[14] = displayTwo;
                break;

            case 53:
                divergenceArray[14] = displayThree;
                break;

            case 54:
                divergenceArray[14] = displayFour;
                break;

            case 55:
                divergenceArray[14] = displayFive;
                break;

            case 56:
                divergenceArray[14] = displaySix;
                break;

            case 57:
                divergenceArray[14] = displaySeven;
                break;

            case 58:
                divergenceArray[14] = displayEight;
                break;

            case 59:
                divergenceArray[14] = displayNine;
                break;
        }
    }
    //!GET SECOND

}