#include <stdio.h>
#include "NumClass.h"


//factorial
int factorial(int num){
int fact =1;

for(int i =1;i*i<=num;i++){
    fact = fact * i;
}
    return fact;
}

//is strong

int isStrong(int num){

if (num <= 0){ //the number can not be negative
    return 0;
}
int temp=num;
int tempNum = 0;
int sumOfFact =0;

while (temp != 0){


tempNum =temp%10;
sumOfFact = sumOfFact +factorial(tempNum);
temp = temp /10; 


}



if (num == sumOfFact){
    return 1;
}
    return 0;
}



/* is prime */

int  isPrime(int number) {

if (number < 1){
    return 0;
}
for( int i =2;i * i <= number;i++){ //there is more efficiency way
    if(number % i == 0){
        return 0;
    }
}

return 1 ;
}




// int main() {  /////// test the function to remove !!!!!!!! /////////////////////////
//     int num =13 ;

//      int num1 = 121;
    
//     // printf("Enter a number: ");
//     // scanf("%d", &num);

//     if (isPrime(num)) {
//         printf("%d is a prime number.\n", num);
//     } else {
//         printf("%d is not a prime number.\n", num);
//     }

//     if (isStrong(num)) {
//         printf("%d is a strong number.\n", num);
//     } else {
//         printf("%d is not a strong number.\n", num);
//     }



// }