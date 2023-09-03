#include <stdio.h>
#include <stdlib.h>

int main()
{int i,j;
    int mat1[2][3]={1,2,3,4,5,6};
    int mat2[2][3]={6,5,4,3,2,1};
    int mat3[2][3];
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            mat3[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d",mat3[i][j]);
        }
        printf("\n");
    }
    return 0;
}
