#include <stdio.h>
#include <stdlib.h>
struct Database
{
    char Student_Name[25];
    int Student_Age;
    int Student_Degree;
    int Student_Section;
};
void print(struct Database* P);
int main()
{
    unsigned int num;
    printf("Enter the student number to get his data: ");
    scanf("%d",&num);
    struct Database Db[5]={"Mohammed Khalid",20,98,1,
                           "Salma Hassan",21,95,3,
                           "Aya Ashour",19,99,4,
                           "Ahmed Samy",22,97,2,
                           "Omar Adel",18,93,5};
    struct Database* ptr=&Db[num-1];
    if(num<=5 && num>0)
    {
      print(ptr);
    }
    else
    {
      printf("Wrong number!");
    }
    return 0;
}
void print(struct Database* P)
{
    printf("\n");

    printf("Name   : %s\n",P->Student_Name);

    printf("Age    : %d\n",(*P).Student_Age);

    printf("Degree : %d\n",P->Student_Degree);

    printf("Section: %d\n",(*P).Student_Section);
}



