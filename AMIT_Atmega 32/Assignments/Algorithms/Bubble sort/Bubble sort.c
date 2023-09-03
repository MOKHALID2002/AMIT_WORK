#include <stdio.h>
#include <stdlib.h>
void bubble(int array[],int length);
int main()
{
    int len,i;
    printf("Enter the length of your array: ");
    scanf("%d",&len);
    int arr[len];
    len=sizeof(arr)/sizeof(arr[0]);
    printf("\nEnter your array: ");
    for(i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nThe entered array before sorting: ");
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\nThe array in an ascending order: ");
    bubble(arr,len);
    return 0;
}
void bubble(int array[],int length){
int n,c,a,temp;
for(n=0;n<length-1;n++){
    for(c=0;c<length-1-n;c++){
        if(array[c]>array[c+1]){
            temp=array[c];
            array[c]=array[c+1];
            array[c+1]=temp;
        }
     }
}
for(a=0;a<length;a++){
        printf("%d ",array[a]);
    }
}





