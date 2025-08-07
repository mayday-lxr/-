#include"SeqListInit.h"
//��ʼ��
void SeqListInit(SL* ps)
{

	//malloc	��̬�ڴ���亯��������δ��ʼ�����ڴ��ַ
	//sizeof(SLDataType)���㵥��Ԫ�صĴ�С���� int Ϊ 4 �ֽڣ�
	//*4�������� 4 ��Ԫ�صĿռ�
	//(SLDataType*)�� malloc ���ص� void* ǿ��ת��Ϊ��������ָ��

	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(-1);

	}

	ps->size = 0;
	ps->capacity = 4;
	printf("��ʼ���ɹ�\n");
}

//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	//�����ѷ����ڴ��Ĵ�С
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;

		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");

			exit(-1);
		}

	}


	ps->a[ps->size] = x;
	ps->size++;



}
//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}
//ͷ��
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
//����λ�õĲ���ɾ��
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
//ɾ��
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

	printf("��ʼ��ӡ\n");
	SeqListCheckCapacity(ps);
	for (int i = 0; i < ps->size; i++)
	{

		printf("%d  ", ps->a[i]);

	}
	printf("\n");

}
void SeqListCheckCapacity(SL* ps)
{


	//�������Ҫ����
	if (ps->size >= ps->capacity)
		ps->capacity *= 2;

	ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
	if (ps->a == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}



}
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;

}