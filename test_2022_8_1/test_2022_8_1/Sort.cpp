#include "Sort.h"

//直接插入排序
void InsertSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; //已有序序列的最后一个元素的下标
		int tmp = v[end + 1]; //本次待插入元素
		while (end >= 0)
		{
			if (tmp < v[end])
			{
				v[end + 1] = v[end];
				end--;
			}
			else
			{
				break;
			}
		}
		v[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(vector<int>& v)
{
	int n = v.size();
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2; //gap折半
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = v[end + gap];
			while (end >= 0)
			{
				if (tmp < v[end])
				{
					v[end + gap] = v[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			v[end + gap] = tmp;
		}
	}
}

//选择排序1
void SelectSort1(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		//在下标为[i,n-1]的元素中找到最小的元素
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		//将最小的元素放到下标为i的位置
		swap(v[i], v[min]);
	}
}

//选择排序2
void SelectSort2(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n / 2; i++)
	{
		//在下标为[i,n-i-1]的元素中找到最小的元素和最大的元素
		int min = i, max = i;
		for (int j = i + 1; j <= n - i - 1; j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
			if (v[j] > v[max])
			{
				max = j;
			}
		}
		//将最小的元素放到下标为i的位置，最大的元素放到下标为n-i-1的位置
		swap(v[i], v[min]);
		if (i == max) //最大值在i的位置，此时最大值已经被换到min的位置了
			max = min;
		swap(v[n - i - 1], v[max]);
	}
}

//堆的向下调整算法
void AdjustDown(vector<int>& v, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n&&v[child + 1] > v[child])
		{
			child++;
		}
		if (v[child] > v[parent])
		{
			swap(v[parent], v[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(vector<int>& v)
{
	int n = v.size();
	//建大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(v, n, i);
	}
	int end = n - 1;
	while (end)
	{
		swap(v[0], v[end]);
		AdjustDown(v, end, 0);
		end--;
	}
}

//冒泡排序
void BubbleSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++) //需要进行n-1躺冒泡排序
	{
		bool flag = true;
		for (int j = 0; j < n - i - 1; j++) //第i躺需要进行n-i-1次比较
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				flag = false;
			}
		}
		if (flag == true) //该躺冒泡排序没有进行过交换，说明已经有序
			break;
	}
}

//快速排序（Hoare版本）
void QuickSort1(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		while (left < right&&v[right] >= v[keyi]) //right向左走，找小
		{
			right--;
		}
		while (left < right&&v[left] <= v[keyi]) //left向右走，找大
		{
			left++;
		}
		if (left < right)
		{
			swap(v[left], v[right]);
		}
	}
	int meeti = left;
	swap(v[keyi], v[meeti]);

	QuickSort1(v, begin, meeti - 1);
	QuickSort1(v, meeti + 1, end);
}