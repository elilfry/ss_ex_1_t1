
#include <stdio.h>
#include "NumClass.h" 


int main() { 
   
   int start, end;

    //printf("Enter two integers separated by a space: "); //delet before pass the ex
    scanf("%d %d", &start, &end);

      if (start > end){
      int temp = end;
      end = start;
      start = temp;
    }


    printf("The Armstrong numbers are:");
    for(int i=start;i<=end;i++){
        if(isArmstrong(i)){
            printf(" %d", i);
        }
    }
    
    printf("\nThe Palindromes are:");
    for(int i=start;i<=end;i++){
        if(isPalindrome(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Prime numbers are:");
    for(int i=start;i<=end;i++){
        if(isPrime(i)){
            printf(" %d", i);
        }
    }

    printf("\nThe Strong numbers are:");
    for(int i=start;i<=end;i++){
        if(isStrong(i)){
            printf(" %d", i);
        }
    }
   
   printf("\n");

   return 0;

}