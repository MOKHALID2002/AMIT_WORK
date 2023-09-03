#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter the number:\n");
    scanf("%d",&x);

    if(x&1==1){
        printf("The number is odd=1");
        printf("\nThe number is even=0");
    }
    else{
        printf("The number is odd=0");
        printf("\nThe number is even=1");
    }
    return 0;
}
