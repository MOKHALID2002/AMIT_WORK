#include <stdio.h>
#include <stdlib.h>
#include "single linked list.h"
Node* CreateList(Node* start)
{
    int NumberofNodes,Data,counter;
    printf("Enter the number of nodes: ");
    scanf("%d",&NumberofNodes);
    printf("Enter the first element to be inserted: ");
    scanf("%d",&Data);
    start=INSERTInBeginning(start,Data);
    for(counter=1;counter<NumberofNodes;++counter){
        printf("Enter the next element to be inserted: ");
        scanf("%d",&Data);
        INSERTAtEnd(start,Data);
    }
    return start;
}

Node* INSERTInBeginning(Node* start,int Data){
//create node
Node* temp=(Node*)malloc(sizeof(Node));

if(temp!=NULL){
    temp -> info=Data;
    temp -> link=start;
    start=temp;
}
return start;
}

void INSERTAtEnd(Node* start,int Data){
Node* temp=(Node*)malloc(sizeof(Node));
if(temp!=NULL){
    Node* ptr=start;
    while(ptr->link!=NULL){
        ptr=ptr -> link;
    }
    temp -> info=Data;
    ptr -> link=temp;
    temp -> link=NULL;
}
}

void DisplayList(Node* start)
{
  Node* ptr=start;
  printf("List is : \n");
  while(ptr!=NULL){
    printf("%d\n",ptr->info);
    ptr=ptr -> link;
  }
}

Node* DeleteNode(Node* start,int Data)
{
    Node* ptr=start;
    Node* temp=(Node*)malloc(sizeof(Node));
    if(start->info==Data){
       temp=start;
       start=start->link;
       free(temp);
    }
    ptr=start;
    while(ptr->link!=NULL){
        if(ptr->link->info==Data){
            break;
        }
        ptr=ptr->link;
    }
    if(ptr->link=NULL){
        printf("\nNode not found");
    }
    else{
        temp=ptr->link;
        ptr->link=temp->link;
        free(temp);
    }
return start;
}


