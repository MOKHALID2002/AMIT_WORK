#ifndef linkedlist_H_
#define linkedlist_H_

typedef struct n
{
int info;
struct n* link;
}Node;
Node* CreateList(Node* start);

Node* INSERTInBeginning(Node* start,int Data);

void INSERTAtEnd(Node* start,int Data);

void DisplayList(Node* start);

Node* DeleteNode(Node* start,int Data);

#endif
