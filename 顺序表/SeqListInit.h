#pragma once
// shabi
#include <stdio.h>
#include< stdlib.h >
#include"assert.h"


typedef int SLDataType;// 明确表示这是顺序表的数据类型
#define N 10

typedef struct  SeqList
{
	SLDataType* a;
	int size;
	int capacity;

}SL, Seqlist;
//初始化
void SeqListInit(SL* ps);
//尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

void SeqListPrint(SL* ps);

void SeqListCheckCapacity(SL* ps);
//销毁
void SeqListDestroy(SL* ps);