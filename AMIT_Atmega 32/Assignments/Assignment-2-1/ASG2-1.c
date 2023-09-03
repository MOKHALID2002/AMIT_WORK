#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y,ans;
    char o;
    printf("Enter Number_1:\n");
    scanf("%f",&x);
    printf("Enter the operator:\n");
    scanf("%s",&o);
    printf("Enter Number_2:\n");
    scanf("%f",&y);
    switch(o){
    case '+':ans=x+y;
    printf("The result is %0.4f",ans);
    break;
    case '-':ans=x-y;
    printf("The result is %0.4f",ans);
    break;
    case '*':ans=x*y;
    printf("The result is %0.4f",ans);
    break;
    case '/':ans=x/y;
    printf("The result is %0.4f",ans);
    break;
    }
    return 0;
}
