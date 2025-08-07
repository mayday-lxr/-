#include <stdio.h>
#include <stdlib.h>
#include"SeqListInit.h"

int* singleNumbers(int* nums, int numsize, int* returnsize)
{
	int ret = 0;
	for (int i = 0; i < numsize; i++)
	{
		ret = ret ^ nums[i];

	}
	int m = 0;
	while (m < 32)
	{
		if (ret & (1 << m))
		{
			break;

		}

		else
			++m;
	}

	int x1 = 0;
	int x2 = 0;
	for (int j = 0; j < numsize; j++)
	{
		if (nums[j] & (1 << m))
		{
			x1 ^= nums[j];

		}
		else
		{
			x2 ^= nums[j];
		}
	}

	int* retArr = (int*)malloc(sizeof(int) * 2);
	retArr[0] = x1;
	retArr[1] = x2;
	*returnsize = 2;
	return retArr;

}

void TestSeqList()
{
	printf("开始调用\n");
	SeqList s;

	SeqListInit(&s);


	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);


	SeqListPrint(&s);


	SeqListInsert(&s, 3, 7);
	SeqListPrint(&s);
}

int main()
{
	//int nums[] = { 4, 1, 4, 6 };
	//int size;  
	//int* result = singleNumbers(nums, 4, &size);  
	//printf("Unique numbers: %d, %d\n", result[0], result[1]);

	TestSeqList();

	return 0;
}