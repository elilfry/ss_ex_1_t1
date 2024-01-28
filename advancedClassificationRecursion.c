
#include "NumClass.h"
int powe(int this, int by){
    int powed = 1;
    for(int i=0; i<by;i++){
        powed = powed * this;
    }
    return powed;
}

int isArmstrongHelper(int num, int size){
    if(num < 10){ return powe(num,size); }
    return powe(num%10,size) + isArmstrongHelper(num/10,size);
}

int isPalindromeHelper(int num, int revNum){
    if(num == 0){ return revNum; }
    revNum = revNum*10 + num%10;
    return isPalindromeHelper(num/10,revNum);
}

int isArmstrong(int num){
    int size = 0, cNum = num;
    while(cNum > 0){ 
        size++;
        cNum = cNum/10;    
    }
    if(isArmstrongHelper(num, size) == num){ return 1; }
    return 0;
}


int isPalindrome(int num){
    if(isPalindromeHelper(num,0) == num){ return 1; }
    return 0;
}
