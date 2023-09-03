#include <stdio.h>
#include <stdlib.h>
void swap(int x,int y);
int main()
{
    int n1,n2;
    printf("Enter first number: \n");
    scanf("%d",&n1);
    printf("Enter second number: \n");
    scanf("%d",&n2);
    swap(n1,n2);
    return 0;
}
void swap(int x,int y)
{
printf("Before swapping\n");
printf("x=%d    y=%d",x,y);
x=y+x;
y=x-y;
x=x-y;
printf("\nAfter swapping\n");
printf("x=%d    y=%d",x,y);
}
