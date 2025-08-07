#include"SeqListInit.h"
//初始化
void SeqListInit(SL* ps)
{

	//malloc	动态内存分配函数，返回未初始化的内存地址
	//sizeof(SLDataType)计算单个元素的大小（如 int 为 4 字节）
	//*4分配容纳 4 个元素的空间
	//(SLDataType*)将 malloc 返回的 void* 强制转换为具体类型指针

	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败");
		exit(-1);

	}

	ps->size = 0;
	ps->capacity = 4;
	printf("初始化成功\n");
}

//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//调整已分配内存块的大小
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;

		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");

			exit(-1);
		}

	}


	ps->a[ps->size] = x;
	ps->size++;



}
//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	int end = ps->size - 1;

	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;

	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps)
{
	int i = 0;
	while (i < ps->size - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);
	assert(pos < ps->size&& pos>0);

	for (int i = ps->size - 1; i >= pos - 1; i--)
	{
		ps->a[i + 1] = ps->a[i];


	}
	ps->a[pos - 1] = x;
	ps->size++;

}
//删除
void SeqListErase(SL* ps, int pos)
{
	assert(ps);


	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];


	}
	ps->size--;

}

void SeqListPrint(SL* ps)
{

	printf("开始打印\n");
	SeqListCheckCapacity(ps);
	for (int i = 0; i < ps->size; i++)
	{

		printf("%d  ", ps->a[i]);

	}
	printf("\n");

}
void SeqListCheckCapacity(SL* ps)
{


	//如果满需要增容
	if (ps->size >= ps->capacity)
		ps->capacity *= 2;

	ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
	if (ps->a == NULL)
	{
		printf("扩容失败\n");
		exit(-1);
	}



}
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;

}