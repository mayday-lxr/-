#include"SList.h"
#include <assert.h>

// ��ӡ����
void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while(cur)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// �����ڵ�
SListNode* CreateSListNode(SListDataType x)
{
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode != NULL); // ȷ���ڴ����ɹ�
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

// β�巨
void SListPushBack(SListNode** pphead, SListDataType x)
{
    SListNode* newnode = CreateSListNode(x);

    if(*pphead == NULL){
      *pphead = newnode;
    }
    else{
        //���ʱ����Ҫ�ҵ�β���Ľ��ָ��
        SListNode* cur = *pphead;
        SListNode* tail = NULL;
        //����������õ���һ��cur->next
        //��ô�Ͳ���Ҫtail�������ַ��
        while(cur)
        {
            tail = cur;
            cur = cur->next;
        }
        tail->next = newnode;
    }
}

// ʵ��βɾ
void SListPopBack(SListNode** pphead)
{
    // �������Ϊ��
    if(*pphead == NULL){
        return;
    }
    // ������ֻ�洢��һ������
    else if((*pphead)->next == NULL){
        free(*pphead);
        *pphead = NULL;
        return;
    }
    //�����е������Ǵ���һ,���ʱ����Ҫ�ҵ�β���ڵ��ǰһ���ڵ�
    //�����������
    // 1. �ͷ����һ���ڵ�
    // 2. ǰһ���ڵ��ָ����Ϊ��
    else{
        SListNode* tail = *pphead;
        SListNode* prev = NULL;
        // ���ѭ������ʱtail�������һ��ֵ��prev��¼��ǰһ������
        while(tail->next != NULL)
        {
            // ָ�����ڵ�β
            prev = tail;
            // ָ����һ��
            tail = tail->next;
        }
        free(tail);
        // �����������һ���Ļ��������Ұָ�������
        prev->next = NULL;
    }
    
}



