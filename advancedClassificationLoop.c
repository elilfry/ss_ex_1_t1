
#include <stdio.h>
#include "NumClass.h"



// is palindrome

int isPalindrome(int num){

    int originalNumber = num;
    int reversedNumber = 0;

    
    while(originalNumber>0){  //creat a reversed number

        int digits = originalNumber%10;
        reversedNumber = reversedNumber * 10 + digits;
        originalNumber = originalNumber /10;

    }

    if(num == reversedNumber){  // check if the reversed num == reversed num
        return 1;
    }


    return 0;
}

//is armstrong



int power(int num,int power){
int powSum =1;

for (int i=0;i< power;i++){

    powSum = powSum *num;
}
return powSum;

}

int numberOfDigits(int num){
   int numberOfDigits = 0;
    while (num >0){
        numberOfDigits ++;
        num = num /10;
    }
    return numberOfDigits;
}

int isArmstrong(int num) {
 int originalNumber = num;
 int sumOfPower = 0;\
 int len = numberOfDigits(num);
 int tempDigit=0;

 while(originalNumber >0){ //calc the sum of the n th power of its digits
     tempDigit = originalNumber %10;
    sumOfPower =sumOfPower + power(tempDigit,len);
    originalNumber = originalNumber/10;
 }

if (num == sumOfPower){
    return 1;
}

    return 0;
}