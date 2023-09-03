#include <stdio.h>
#include <stdlib.h>
void func(int*,int*,int*,int*);
int main()
{
    int a;
    int b;
    int sum,sub;
    printf("Enter two numbers: \n");
    scanf("%d %d",&a,&b);

    func(&a,&b,&sum,&sub);
    printf("The sum is %d\n",sum);
    printf("The sub is %d",sub);
    return 0;
}
void func(int* x,int* y,int* sum,int* sub){
*sum=*x + *y;
*sub=*x - *y;
}
