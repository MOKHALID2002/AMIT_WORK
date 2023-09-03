#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct st
    {
        int x;
        char* p;    //declaration
    };

    struct st A;
    A.p="Name: Mohammed\n";
    printf("%s",A.p);
    printf("age: ");
    scanf("%d",&A.x);
    printf("%d",A.x);
    return 0;
}
