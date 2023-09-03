#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[]={12,24,36,44,51,67,80,102};
    int num,R_index,L_index,M_index;
    int len;
    printf("The value is = ");
    scanf("%d",&num);
    len=sizeof (arr)/sizeof (arr[0]);
    R_index=len-1;
    L_index=0;
    while(L_index<=R_index){
        M_index=(R_index+L_index)/2;
        if(arr[M_index]==num){
            printf("Correct number..Congrats..%d",M_index);
            return 0;
        }
        else if(num>arr[M_index]){
            L_index=M_index+1;
        }
        else if(num<arr[M_index]){
            R_index=M_index-1;
        }

    }
    printf("The number is wrong..Sorry");
    return 0;
}
