#include <stdio.h>
#include <stdlib.h>
int* op(int num1,int num2);
int main()
{
    int x,y;
    int* z;
    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);
    z=op(x,y);
    printf("sum is %d  sub is %d  pro is %d  avg is %d",*z,*(z+1),*(z+2),*(z+3));
    return 0;
}
int* op(int num1,int num2){
static int arr[4];
arr[0]=num1+num2;
arr[1]=num1-num2;
arr[2]=num1*num2;
arr[3]=(num1+num2)/2;

    return arr;
}

