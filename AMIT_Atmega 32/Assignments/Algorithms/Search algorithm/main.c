#include <stdio.h>
#include <stdlib.h>
void binary(int array[],int length,int value);
int main()
{
    int num;
    int arr[]={5,12,23,38,44,52,65,70,89,94,101,288};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("Test variable: ");
    scanf("%d",&num);
    binary(arr,len,num);
    return 0;
}
void binary(int array[],int length,int value){
int L,R,M;
L=0;
R=length-1;
while(L<=R){
    M=(L+R)/2;
    if(array[M]==value){
        printf("%d is Correct.....Index: %d",value,M);
        return;
    }
    else if(value>array[M]){// update left
        L=M+1;
    }
    else if(value<array[M]){// update right
        R=M-1;
    }
}
printf("%d is not correct",value);

}
