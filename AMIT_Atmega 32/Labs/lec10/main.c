#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len,i;
    printf("The length is: ");
    scanf("%d",&len);
    char* ptr=(char*) malloc (len * sizeof(char));
    for(i=0;i<len;i++){
        scanf("%d",&ptr[i]);
    }
for(i=0;i<len;i++){
        printf("%d  ",ptr[i]);
    }
    return 0;
}
