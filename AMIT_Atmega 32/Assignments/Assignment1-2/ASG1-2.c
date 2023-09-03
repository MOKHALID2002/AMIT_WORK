#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first_num,n,s,second_num;// n=number of bit
    int x=1;
    printf("Enter any number: ");
    scanf("%d",&first_num);

    printf("Enter nth bit to toggle or invert (0-31): ");
    scanf("%d",&n);

    if(n<32){
    s=x<<n;
    second_num=first_num^s;

    printf("Bit toggled successfully\n");

    printf("\nNumber before toggling 1 bit = %d",first_num);

    printf("\nNumber after toggling 1 bit = %d",second_num);
    }
    return 0;
}

