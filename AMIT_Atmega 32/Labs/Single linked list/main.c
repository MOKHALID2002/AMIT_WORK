#include <stdio.h>
#include <stdlib.h>
#include "single linked list.h"
int main()
{
    Node* List=NULL;
    List=CreateList(List);
    DisplayList(List);
    List=DeleteNode(List,4);
    DisplayList(List);
    return 0;
}
