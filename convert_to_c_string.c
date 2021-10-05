/*
 * convert_to_c_string.c
 *
 *  Created on: Nov 27, 2017
 *      Author: alexa
 */
#include "convert_to_c_string.h"
#include <stdint.h>




void convert_long_to_char(long signed_integer, char* saveDigitsHere){

    char int_is_negative = 0;
    if ( signed_integer < 0 ){
       int_is_negative = 1;
       signed_integer = -signed_integer;
    }

    char num_of_digits = getNumOfDigitsInt32(signed_integer, int_is_negative);

    long digits[6] = {0};

    if ( signed_integer < 10 ) //getting the digits
        digits[0] = signed_integer;
	int i;
	
	
    else if ( signed_integer >= 10 && signed_integer  < 100 )
    {
        digits[0] =  signed_integer/10;
        digits[1] =  signed_integer - digits[0]*10;
    }
    else if ( signed_integer >= 100 && signed_integer  < 1000 )
    {
        digits[0] =  signed_integer/100;
        digits[1] =  (signed_integer - digits[0]*100)/10;
        digits[2] =  signed_integer - (digits[0]*100 + digits[1]*10);
    }
    else if ( signed_integer >= 1000 && signed_integer  < 10000 )
    {
        digits[0] =  signed_integer/1000;
        digits[1] =  (signed_integer - digits[0]*1000)/100;
        digits[2] =  (signed_integer - (digits[1]*100 + digits[0]*1000) )/10;
        digits[3] =  signed_integer - (digits[2]*10 + digits[1]*100 + digits[0]*1000);
    }
    else if ( signed_integer >= 10000 && signed_integer  < 100000 )
    {
        digits[0] =  signed_integer/10000;
        digits[1] =  (signed_integer - digits[0]*10000)/1000;
        digits[2] =  (signed_integer - (digits[1]*1000 + digits[0]*10000) )/100;
        digits[3] =  (signed_integer - (digits[2]*100 + digits[1]*1000 + digits[0]*10000) )/10;
        digits[4] =  signed_integer - (digits[3]*10 + digits[2]*100 + digits[1]*1000 + digits[0]*10000);
    }
    else if ( signed_integer >= 100000 && signed_integer  < 1000000 )
    {
        digits[0] =  signed_integer/100000;
        digits[1] =  (signed_integer - digits[0]*100000)/10000;
        digits[2] =  (signed_integer - (digits[1]*10000 + digits[0]*100000 ) )/1000;
        digits[3] =  (signed_integer - (digits[2]*1000 + digits[1]*10000 + digits[0]*100000 ) )/100;
        digits[4] =  (signed_integer - (digits[3]*100 + digits[2]*1000 + digits[1]*10000 + digits[0]*100000 ) )/10;
        digits[5] =  signed_integer - ( digits[4]*10 + digits[3]*100 + digits[2]*1000 + digits[1]*10000 + digits[0]*100000 );
    }

    for(unsigned char i=0; i < 7; i++ ){
        if ( i < num_of_digits ) { //where the number is
            if (int_is_negative){
                if (i == 0 )
                    saveDigitsHere[0] = '-';
                else
                    saveDigitsHere[i] = (char)digits[i-1] + 48; //it starts at the end (MSB)
            }
            else
                saveDigitsHere[i] = (char)digits[i]  + 48; //it starts at the end (MSB)
        }
        else
            saveDigitsHere[i] = (char)digits[i];
    }

    saveDigitsHere[7] = '\0';
}

unsigned char getNumOfDigitsInt32(long integer, char isnegative){
    if ( isnegative) {
        if ( integer  < 10 )
            return 2;//1 char for the negative sign
        else
            return (
                    2 + getNumOfDigitsInt32( (integer/10), 0 )
                    ); //negative - next not negative
    }
    else
        if ( integer < 10 )
            return 1; //one digit

    return (
            1 + getNumOfDigitsInt32( (integer/10), 0 )
            );
}


char convertDigit_to_char(char num){
    char newDigit;
    switch(num){
    case 0:
            newDigit = '0';
            break;
    case 1:
            newDigit = '1';
            break;
    case 2:
            newDigit = '2';
            break;
    case 3:
            newDigit = '3';
            break;
    case 4:
            newDigit = '4';
            break;
    case 5:
            newDigit = '5';
            break;
    case 6:
            newDigit = '6';
            break;
    case 7:
            newDigit = '7';
            break;
    case 8:
            newDigit = '8';
            break;
    case 9:
            newDigit = '9';
            break;
    default:
        newDigit = '\0';
        break;
    }
    return newDigit;
}

