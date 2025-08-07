#pragma once
// shabi
#include <stdio.h>
#include< stdlib.h >
#include"assert.h"


typedef int SLDataType;// ��ȷ��ʾ����˳������������
#define N 10

typedef struct  SeqList
{
	SLDataType* a;
	int size;
	int capacity;

}SL, Seqlist;
//��ʼ��
void SeqListInit(SL* ps);
//β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

void SeqListPrint(SL* ps);

void SeqListCheckCapacity(SL* ps);
//����
void SeqListDestroy(SL* ps);