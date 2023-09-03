//Recursion method
#include <stdio.h>
#include <stdlib.h>
int FIB(int num);
int main()
{
    int x;
    printf("Enter the number of terms: ");
    scanf("%d",&x);
    printf("Fibonacci series: ");
    for(int i=0;i<x;i++){
       printf("%d  ",FIB(i));
    }
    return 0;
}

int FIB(int num){
    if(num<=1){
        return num;
    }
    else{
        return FIB(num-1)+FIB(num-2);
    }
}
