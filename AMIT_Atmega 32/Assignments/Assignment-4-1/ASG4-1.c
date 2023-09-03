#include <stdio.h>
#include <stdlib.h>
void edit(int* ans,int num);
int main()
{
    int x;
    int* q=&x;
    int* c=&x;
    printf("Please enter the value of x: ");
    scanf("%d",&x);
    printf("Before calling edit x = %d\n",x);
    edit(q,*c);
    printf("After calling edit x = %d",x);
    return 0;
}
void edit(int* ans,int num){
    *ans=*ans+1;
    printf("Enter the numbers [5,20,80] : ");
    for(int i=1;i<4;i++){
        scanf("%d",&num);
        printf("%d = %d\n",i,num);
    }
}
