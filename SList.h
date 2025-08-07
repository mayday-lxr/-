#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//����ʵ�ֵ���һ������
typedef int SListDataType;
#define N 10

typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SListNode;

//β��βɾ
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
//ͷ��ͷɾ
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//ָ��λ�ò����ɾ��
void SListInsert(SListNode** pphead, int pos, SListDataType x);
void SListErase(SListNode** pphead, int pos);

//��ӡ����
void SListPrint(SListNode* phead);

//�����ڵ�
SListNode* CreateSListNode(SListDataType x);