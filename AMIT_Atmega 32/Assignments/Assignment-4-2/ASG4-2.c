#include <stdio.h>
#include <string.h>

int main()
{
    char str[120];
    int length,i;
    printf("String: ");
    gets(str);
    length=strlen(str);
    printf("\nOriginal string: %s\n",str);
    printf("\nReversed string: ");
    for(i=length-1;i>=0;i--){
        if(str[i]==' '){
            str[i]='\0';
            printf("%s ",&str[i]+1);
        }
    }
     printf("%s",str);
    return 0;
}
