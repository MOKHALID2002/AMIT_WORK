#include <stdio.h>
#include <stdlib.h>
void lin_search(int arr1[],int length,int value);
int main()
{
    int len;
    int arr[]={23,44,35,8,12,96,1};
    len=sizeof(arr)/sizeof(arr[0]);
    int num;
    printf("Enter test variable: ");
    scanf("%d",&num);
    lin_search(arr,len,num);
    return 0;
}
void lin_search(int arr1[],int length,int value){int i,flag=0;
for(i=0;i<length;i++){
    if(arr1[i]==value){
        printf("Found in %d",i);
        flag++;
        break;
    }
}
if(flag==0){
printf("Not found");
}
}
/* Another solutions
- line 20--> return;    no if in line 23
- break in line 20+if condition(arr[i]!=value) in line 23  */
