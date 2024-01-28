#include <stdio.h>
#include "NumClass.h" 


//////////////////// is palindrome//////////////////

// is palindrome

    if (number == 0)
    {
        return 0;
    }
    //
    return 1 + digitCount(number / 10);
}

int powerNRec(int number, int n){
    if (n > 0)
    {
        return (number * powerNRec(number, n-1));
    }
    return 1;
}

int isPalindrome(int number){
    if (digitCount(number) <= 1)
    {
        return 1;
    }
    
    int firstDigit = number / powerNRec(10, (digitCount(number))-1);
    int lastDigit = number % 10;

    if (firstDigit != lastDigit)
    {
        return 0;
    }
    
    return isPalindrome((number % powerNRec(10, digitCount(number)-1))/10);
}
/////////////////////// isArmstrong ///////////////////////

int isArmstrongHelper(int num, int digits){

    if(num == 0) return 0;

    return powerNRec(num % 10, digits) + isArmstrongHelper(num/10,digits);
}

int isArmstrong(int num){

    if(num <= 0) return 0;

    int numOfDigits = digitCount(num);

    if(isArmstrongHelper(num,numOfDigits)==num){
        return 1;}

    return 0;
}