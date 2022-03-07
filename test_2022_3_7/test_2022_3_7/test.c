#include <stdio.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int start = 0; //��¼�������е�һ��Ԫ�ص��±�
		int end = i; //��¼�����������һ��Ԫ�ص��±�
		int tmp = a[end + 1]; //���ִ������Ԫ��
		//1��ͨ�����ֲ����ҵ�tmpӦ�ò��뵽�������е��ĸ�λ��
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
		//2���Ƚ�end+1��i��Ԫ����������Ųһλ
		for (int j = i; j >= end + 1; j--)
		{
			a[j + 1] = a[j];
		}
		//3���ٽ�tmp�ŵ�end+1��λ��
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