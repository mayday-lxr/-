#include"SList.h"


int main()
{
    SListNode* Node = NULL;
   
    SListPushBack(&Node, 1);
    SListPushBack(&Node, 2);
    SListPushBack(&Node, 3);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    SListPopBack(&Node);
    SListPrint(Node);
    printf("NULL\n");
}