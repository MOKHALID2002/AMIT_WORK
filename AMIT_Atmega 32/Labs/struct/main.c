#include <stdio.h>
#include <stdlib.h>
struct st{
int sum,sub,mult;
float avg,div;
};
struct st fun(int num1,int num2);
int main()
{
    int x,y;
    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);
    struct st s=fun(x,y);
    printf("\nsum is %d sub is %d mult is %d avg is %f div is %f",s.sum,s.sub,s.mult,s.avg,s.div);
    return 0;
}

struct st fun(int num1,int num2){
struct st A;
A.sum=num1+num2;
A.sub=num1-num2;
A.mult=num1*num2;
A.avg=(float)(num1+num2)/2;
A.div=(float)num1/num2;
return A;
}
