/*
***************************************************************************************************************
***************************************************************************************************************
**************************************       Name:عمار محمود محمد       ***************************************
**************************************       Group:D38 - Online         ***************************************
**************************************       Assignment:C Project       ***************************************
***************************************************************************************************************
***************************************************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Headers.h"
#define length 2
int checkfull;
int main()
{
uint8 Operation,Addc,CheckAdd,grades[3],subjects[3],id,year,i,number,exist=0;
List:
    printf("\n------->(Data Base)<-------\n");
    printf("\n (1)-Add new entry to the database");
    printf("\n (2)-Display data of an entry using ID");
    printf("\n (3)-Check if ID exists full");
    printf("\n (4)-Check if the database is full");
    printf("\n (5)-Delete entry using the ID");
    printf("\n (6)-the number of entries");
    printf("\n (7)-Get the list of IDs of the students");
    printf("\n (0)-Close the program\n");
    printf("\n Please pick the Operation: ");
    scanf("%d",&Operation);
    switch (Operation){
      case 1:
          Add:
          for(Addc=checkfull;Addc<length;Addc++){
                if(arr[Addc].student_ID==0){
                        printf("\nPlease enter the Student ID: ");
                        scanf("%d",&id);
                        exist=SDB_IsIdExist(id);
                        if(id==0){
                            printf("\nThe ID can't be Zero Please enter the ID again\n");
                            goto Add;
                        }
                        if(exist==1){
                            printf("\n The ID you entered already exists please enter again");
                            goto Add;
                        }
                        printf("Please enter the Student year: ");
                        scanf("%d",&year);
                        for (i=0;i<3;i++){
                        printf("Please enter Course %d ID: ",i+1) ;
                        scanf("%d",&subjects[i]);
                        printf("Please enter Course %d Grade: ",i+1) ;
                        scanf("%d",&grades[i]);
                        }
                        CheckAdd=SDB_AddEntry(id,year,grades,subjects);
                }
                if(CheckAdd == 1){
                    checkfull++;
                    printf("\nData is added successfully\n ");
                    printf("\n\nEnter (1) to go for the Data base List ");
                    printf("\nor Enter(0) to close the Program : ");
                    scanf("%d",&number);
                    if(number==1)goto List;
                    else goto end ;
                }
                else{
                        arr[Addc].student_ID=0;
                        printf("\nSorry data not added please enter it again: ");
                        printf("\nBe sure the (Grade from 0 to 100) also (Year less than 2023)\n");
                        goto Add;
                }

          }
          printf("\nSorry Data Base is fully ");
          printf("\n\nEnter (1) to go for the Data base List ");
          printf("\nor Enter(0) to close the Program : ");
          scanf("%d",&number);
          if(number==1)goto List;
          else goto end ;
      case 2:
Display:
        printf("\nEnter the ID to Display : ");
        scanf("%d",&id);
        if(id==0){
            printf("\nThe ID can't be Zero Please enter the ID again");
            goto Display;
          }
        if(SDB_IsIdExist(id)){
        SDB_ReadEntry(id);
          printf("\n\nEnter (1) to go for the Data base List ");
          printf("\nor Enter(0) to close the Program : ");
          scanf("%d",&number);
          if(number==1)goto List;
          else goto end ;
        }
        else{
        printf("\n The ID you entered is not exists");
        printf("\nif you want to go for list enter (1) ");
        printf("\nif you need to Display another ID enter (0) : ");
        scanf("%d",&number);
        if(number==1)goto List;
        else goto Display;
        }

      case 3:
Exist:
          printf("\nPlease enter the ID to check : ");
          scanf("%d",&id);
          exist=SDB_IsIdExist(id);
          if(id==0){
            printf("\nThe ID can't be Zero Please enter the ID again");
            goto Exist;
          }
          if(exist==1){
            printf("\n The ID you entered is exists");
            goto List;
          }
          else {
          printf("\n The ID you entered not exists");
          goto List;
          }








    }
end:
    printf("\n \tHave a nice day\n");
    return 0;
}
bool SDB_AddEntry(uint8 id,uint8 year,uint8*g,uint8*c){
if(*g<101&&*(g+1)<101&&*(g+2)<101&&year<2023){
    arr[checkfull].student_ID=id;
    arr[checkfull].student_year=year;
    arr[checkfull].course1_ID=c[0];
    arr[checkfull].course2_ID=c[1];
    arr[checkfull].course3_ID=c[2];
    arr[checkfull].course1_grade=g[0];
    arr[checkfull].course2_grade=g[1];
    arr[checkfull].course3_grade=g[2];
    return 1;
}
else return 0;
}
void SDB_ReadEntry(uint8 id){
uint8 i;
    for(i=0;i<length;i++){
            if(id==arr[i].student_ID){
                    printf("\nStudent ID   : %d",arr[i].student_ID);
                    printf("\nStudent Year : %d",arr[i].student_year);
                    printf("\nCourse 1 ID  : %d",arr[i].course1_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course1_grade);
                    printf("\nCourse 2 ID  : %d",arr[i].course2_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course2_grade);
                    printf("\nCourse 3 ID  : %d",arr[i].course3_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course3_grade);
             }
    }
}
bool SDB_IsIdExist(uint8 id){
    uint8 i;
    for(i=0;i<length;i++){
            if(id==arr[i].student_ID){
                return true;
            }
}
return false;
}
