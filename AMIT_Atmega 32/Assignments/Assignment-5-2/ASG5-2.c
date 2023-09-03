#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    printf("The array length is: ");
    scanf("%d",&len);
    int arr1[len];
    printf("Array: ");
    int i;
    for(i=0;i<len;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Original array: ");
    for(i=0;i<len;i++){
        printf("%d  ",arr1[i]);
    }
    int j=len-1,store;
    i=0;
    while(i<j){
    store=arr1[i];
    arr1[i]=arr1[j];
    arr1[j]=store;
    i++;
    j--;
    }
    printf("\nReversed array: ");
    for(i=0;i<len;i++){
        printf("%d  ",arr1[i]);
    }
    return 0;
}
