#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    int i;
    int max,min;
    printf("Enter the array elements:-\n");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    printf("The ARRAY:\n");
    for(i=0;i<5;i++){
        printf("%d-%d    ",i,arr[i]);
    }
    //printf("\n%d",i);
    printf("\n");
    if(arr[0]>arr[1]&&arr[0]>arr[2]&&arr[0]>arr[3]&&arr[0]>arr[4]){
        printf("Max is %d pos=0",arr[0]);


    }
    else if(arr[1]>arr[0]&&arr[1]>arr[2]&&arr[1]>arr[3]&&arr[1]>arr[4]){
        printf("Max is %d pos=1",arr[1]);
    }
    else if(arr[2]>arr[0]&&arr[2]>arr[1]&&arr[2]>arr[3]&&arr[2]>arr[4]){
        printf("Max is %d pos=2",arr[2]);
    }
    else if(arr[3]>arr[0]&&arr[3]>arr[1]&&arr[3]>arr[2]&&arr[3]>arr[4]){
        printf("Max is %d pos=3",arr[3]);
    }
    else if(arr[4]>arr[0]&&arr[4]>arr[2]&&arr[4]>arr[3]&&arr[4]>arr[1]){
        printf("Max is %d pos=4",arr[4]);
    }
    printf("\n");
    if(arr[0]<arr[1]&&arr[0]<arr[2]&&arr[0]<arr[3]&&arr[0]<arr[4]){
        printf("Min is %d",arr[0]);

    }
    else if(arr[1]<arr[0]&&arr[1]<arr[2]&&arr[1]<arr[3]&&arr[1]<arr[4]){
        printf("Min is %d",arr[1]);
    }
    else if(arr[2]<arr[0]&&arr[2]<arr[1]&&arr[2]<arr[3]&&arr[2]<arr[4]){
        printf("Min is %d",arr[2]);
    }
    else if(arr[3]<arr[0]&&arr[3]<arr[1]&&arr[3]<arr[2]&&arr[3]<arr[4]){
        printf("Min is %d",arr[3]);
    }
    else if(arr[4]<arr[0]&&arr[4]<arr[2]&&arr[4]<arr[3]&&arr[4]<arr[1]){
        printf("Min is %d",arr[4]);
    }

    return 0;
}
