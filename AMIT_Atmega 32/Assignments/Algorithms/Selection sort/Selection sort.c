#include <stdio.h>
#include <stdlib.h>
void selection(int array[],int length);
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
    printf("\n\nThe array in an ascending order:- ");
    selection(arr,len);
    return 0;
}
void selection(int array[],int length){
int i=0,min_index,c,a;
for(i=0;i<length-1;i++){
        min_index=i;
    for(c=i+1;c<length;c++){
       if(array[c]<array[min_index]){
        min_index=c;
       }
    }
    if(min_index!=i){
        array[i]=array[i]^array[min_index];
        array[min_index]=array[i]^array[min_index];
        array[i]=array[i]^array[min_index];
    }
}
for(a=0;a<length;a++){
        printf("%d ",array[a]);
    }
}












