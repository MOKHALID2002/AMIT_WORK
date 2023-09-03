#include <stdio.h>
#include <stdlib.h>
struct A6_2
{
    float real;
    float img;
};
int main()
{
    struct A6_2 Q1,Q2,sum;

    printf("For 1st complex number:-\n");
    printf("Enter the real and imaginary respectively:-\n");
    printf("Real part: ");
    scanf("%f",&Q1.real);
    printf("Imaginary part: ");
    scanf("%f",&Q1.img);

    printf("\nFor 2nd complex number:-\n");
    printf("Enter the real and imaginary respectively:-\n");
    printf("Real part: ");
    scanf("%f",&Q2.real);
    printf("Imaginary part: ");
    scanf("%f",&Q2.img);

    sum.real=Q1.real+Q2.real;
    sum.img=Q1.img+Q2.img;

    printf("\nThe sum is = %0.1f + %0.1fi",sum.real,sum.img);
    return 0;
}
