#include "Sort.h"

//ֱ�Ӳ�������
void InsertSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; //���������е����һ��Ԫ�ص��±�
		int tmp = v[end + 1]; //���δ�����Ԫ��
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

//ϣ������
void ShellSort(vector<int>& v)
{
	int n = v.size();
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2; //gap�۰�
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

//ѡ������1
void SelectSort1(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		//���±�Ϊ[i,n-1]��Ԫ�����ҵ���С��Ԫ��
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		//����С��Ԫ�طŵ��±�Ϊi��λ��
		swap(v[i], v[min]);
	}
}

//ѡ������2
void SelectSort2(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n / 2; i++)
	{
		//���±�Ϊ[i,n-i-1]��Ԫ�����ҵ���С��Ԫ�غ�����Ԫ��
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
		//����С��Ԫ�طŵ��±�Ϊi��λ�ã�����Ԫ�طŵ��±�Ϊn-i-1��λ��
		swap(v[i], v[min]);
		if (i == max) //���ֵ��i��λ�ã���ʱ���ֵ�Ѿ�������min��λ����
			max = min;
		swap(v[n - i - 1], v[max]);
	}
}

//�ѵ����µ����㷨
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
//������
void HeapSort(vector<int>& v)
{
	int n = v.size();
	//�����
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

//ð������
void BubbleSort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++) //��Ҫ����n-1��ð������
	{
		bool flag = true;
		for (int j = 0; j < n - i - 1; j++) //��i����Ҫ����n-i-1�αȽ�
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				flag = false;
			}
		}
		if (flag == true) //����ð������û�н��й�������˵���Ѿ�����
			break;
	}
}

//��������Hoare�汾��
void QuickSort1(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		while (left < right&&v[right] >= v[keyi]) //right�����ߣ���С
		{
			right--;
		}
		while (left < right&&v[left] <= v[keyi]) //left�����ߣ��Ҵ�
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