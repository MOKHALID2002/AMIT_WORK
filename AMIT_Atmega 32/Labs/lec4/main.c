#include <stdio.h>
#include <stdlib.h>
int main()
{int NUM1,NUM2,NUM3,NUM4,NUM5;
    printf("enter 5 numbers \n");
scanf("%d %d %d %d %d",&NUM1,&NUM2,&NUM3,&NUM4,&NUM5);
    int a=avg(NUM1,NUM2,NUM3,NUM4,NUM5);
    printf("The average is %d",a);
    return 0;
}
