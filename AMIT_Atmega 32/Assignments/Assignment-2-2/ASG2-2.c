#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,mod,pro=1,answer=0,dig=0,count;
    printf("Enter any number= ");
    scanf("%d",&num);
    int x=num;
    while(x!=0){
        x/=10;
        dig++;
    }
    count=dig;
    x=num;
     while(x!=0){
        mod=x%10;
        while(count!=0){
            pro*=mod;
            count--;
        }
        answer+=pro;
        count=dig;
        x/=10;
        pro=1;
    }
    if(num==answer){
        printf("Armstrong number.");
    }
    else{
        printf("Not an Armstrong number.");
    }
return 0;
}
