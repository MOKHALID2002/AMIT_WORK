#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr_1[5],i,j;
    for(i=0;i<5;i++){
        printf("Enter element %d : ",i);
        scanf("%d",&arr_1[i]);
    }
    printf("Array: ");
    int store;
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
        if(arr_1[i]>arr_1[j]){
            store=arr_1[i];
            arr_1[i]=arr_1[j];
            arr_1[j]=store;
        }
    }
    }
    for(i=0;i<5;i++){
        printf("%d  ",arr_1[i]);
    }
    printf("\nThe maximum number is %d in position 4",arr_1[4]);
    printf("\nThe minimum number is %d in position 0",arr_1[0]);
    return 0;
}
