//Iterative method
#include <stdio.h>
#include <stdlib.h>

int main()

{
    int NUM,ans;
    int a=0;
    int b=1;
    printf("Please enter your preferred number of elements: ");
    scanf("%d",&NUM);
    printf("Fibonacci series:-\n");
    for(int i=0;i<NUM;i++){
        printf("%d  ",a);
        ans=a+b;
        a=b;
        b=ans;
    }
    return 0;
}
