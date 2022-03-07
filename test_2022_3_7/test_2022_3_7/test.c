#include <stdio.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int start = 0; //记录有序序列第一个元素的下标
		int end = i; //记录有序序列最后一个元素的下标
		int tmp = a[end + 1]; //本轮待插入的元素
		//1、通过二分查找找到tmp应该插入到有序序列的哪个位置
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (tmp < a[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		//2、先将end+1到i的元素依次往后挪一位
		for (int j = i; j >= end + 1; j--)
		{
			a[j + 1] = a[j];
		}
		//3、再将tmp放到end+1的位置
		a[end + 1] = tmp;
	}
}
int main()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	InsertSort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}