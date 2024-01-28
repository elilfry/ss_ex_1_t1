#include "NumClass.h"

int power(int base, int exponent) {  // Changed variable name 'a' to 'exponent'
    int base1 = base;
    if (exponent != 0)
        return (base1 * power(base1, exponent - 1));
    else
        return 1;
}

int isArmstrongHelper(int number, int size) {  // Changed variable name 'num' to 'number'
    if (number < 10) { return power(number, size); }
    return power(number % 10, size) + isArmstrongHelper(number / 10, size);
}

int isPalindromeHelper(int number, int reversedNumber) {  // Changed variable names 'num' to 'number' and 'revNum' to 'reversedNumber'
    if (number == 0) { return reversedNumber; }
    reversedNumber = reversedNumber * 10 + number % 10;
    return isPalindromeHelper(number / 10, reversedNumber);
}

int isArmstrong(int num) {
    int size = 0, currentNum = num;  // Changed variable name 'cNum' to 'currentNum'
    while (currentNum > 0) {
        size++;
        currentNum = currentNum / 10;
    }
    if (isArmstrongHelper(num, size) == num) { return 1; }
    return 0;
}

int isPalindrome(int num) {
    if (isPalindromeHelper(num, 0) == num) { return 1; }
    return 0;
}
