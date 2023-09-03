#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Grade;
    printf("Enter your grade: ");
    scanf("%d",&Grade);
    if(Grade<50){
        printf("Failed");
    }
    else if(Grade<65){
    printf("Pass");
    }
    else if(Grade<75){
    printf("Good");
    }
    else if(Grade<85){
    printf("Very Good");
    }
    else{
        printf("Excellent");
    }
    return 0;
}
