#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"
#define ENT 2

struct SimpleDb
{
    uint8 Student_ID;
    uint8 Student_Year;
    uint8 Course1_ID;
    uint8 Course1_Grade;
    uint8 Course2_ID;
    uint8 Course2_Grade;
    uint8 Course3_ID;
    uint8 Course3_Grade;
} Db[ENT];

uint8 FULL,Loop;

int main()
{
uint8 task,grade[3],subject[3],id,year,i,n,search=0,Check_Add,F;
DataBase:
    printf("\nWELCOME TO MY PROJECT!\n");
    printf("1) Add new entry.\n");
    printf("2) Read an entry.\n");
    printf("3) Number of entries.\n");
    printf("4) Check if the database is full.\n");
    printf("5) Delete the entry with the given ID.\n");
    printf("6) Check if the entered ID exists.\n");
    printf("7) List of students's ID's.\n");
    printf("8) End program.\n");
    printf("\nPlease enter the task --> ");
    scanf("%d",&task);

    switch(task)
    {
case 1:
    Add:
        F=SDB_IsFull();
        if(F==1){
            printf("\nDatabase is Full\n");

           goto DataBase ;
        }

    else{
        for(Loop=0;Loop<ENT;Loop++){
                if(Db[Loop].Student_ID == 0){
                        printf("\nPlease enter the Student ID: ");
                        scanf("%d",&id);
                        search=SDB_IsIdExist(id);
                        if(id==0){
                            printf("\nThe ID can't be Zero Please enter the ID again\n");
                            goto Add;
                        }
                        if(search==1){
                            printf("\nThe ID you entered already exists please enter again");
                            goto Add;
                        }
                        if(id>2000000000){
                            printf("\nWrong ID,Try again");
                            goto Add;
                        }
                        printf("Please enter the Student year: ");
                        scanf("%d",&year);
                        for (n=0;n<3;n++){
                        printf("Please enter Course number %d ID: ",n+1);
                        scanf("%d",&subject[n]);
                        printf("Please enter Course number %d Grade: ",n+1);
                        scanf("%d",&grade[n]);
                        }
                        Check_Add=SDB_AddEntry(id,year,grade,subject);
                        if(Check_Add == 1){
                        FULL++;
                    printf("\nData is added successfully in Position --> %d\n ",Loop+1);
                    goto DataBase;
                }
                else{
                        Db[Loop].Student_ID=0;
                        printf("\nData is not added..please enter it again.");
                        printf("\nCheck your grade (0 to 100).\n");
                        goto Add;
                }
            }

         }
    }

/*
case 2:




case 3:
*/



case 4:
F=SDB_IsFull();
if(F == 1 )
{
    printf("\nDatabase is full.");
           goto DataBase;

}
else
{
       printf("\nThere is space .");
       goto DataBase;
}





/*
case 5:





case 6:






case 7:






default



*/
    }
return 0;
    }

bool SDB_AddEntry(uint8 ID,uint8 Y,uint8* G,uint8* S)
{
    if(G[0]<=100&&G[1]<=100&&G[2]<=100){
    Db[Loop].Student_ID=ID;
    Db[Loop].Student_Year=Y;
    Db[Loop].Course1_ID=S[0];
    Db[Loop].Course2_ID=S[1];
    Db[Loop].Course3_ID=S[2];
    Db[Loop].Course1_Grade=G[0];
    Db[Loop].Course2_Grade=G[1];
    Db[Loop].Course3_Grade=G[2];
    return 1;
}
else
    return 0;

}
bool SDB_IsIdExist(uint8 id)
{
    uint8 a;
    for(a=0;a<ENT;a++){
            if(id==Db[a].Student_ID){
                return true;
            }
}

return false;
}
bool SDB_IsFull(void){
if(FULL == ENT){
 return true;
}
else{
    return false;
}
}


