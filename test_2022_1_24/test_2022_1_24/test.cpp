////煤球数量
//#include <iostream>
//using namespace std;
//int main()
//{
//	int num = 1;
//	int plus = 2;
//	int sum = 1;
//	for (int i = 0; i < 99; i++)
//	{
//		num = num + plus;
//		plus++;
//		sum += num;
//	}
//	cout << sum << endl;
//	return 0;
//} //171700

////生日蜡烛
//#include <iostream>
//using namespace std;
//int main()
//{
//	//方法一
//	for (int i = 1; i <= 100; i++)
//	{
//		for (int j = 1; j <= 100; j++)
//		{
//			if ((i + j)*(j - i + 1) / 2 == 236)
//				cout << i << " " << j << endl;
//		}
//	}
//	//方法二
//	for (int i = 1; i <= 100; i++)
//	{
//		int t = i*(i - 1) / 2;
//		if ((236 - t) % i == 0)
//			cout << ((236 - t) / i) << " " << i << endl;
//	}
//	return 0;
//} //26

////凑算式
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool check(vector<int>& v)
//{
//	int x = v[3] * 100 + v[4] * 10 + v[5];
//	int y = v[6] * 100 + v[7] * 10 + v[8];
//	if (((v[1] * y + v[2] * x) % (v[2] * y) == 0) 
//		&& (v[0] + (v[1] * y + v[2] * x) / (v[2] * y) == 10))
//		return true;
//	return false;
//}
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int count = 0;
//	do
//	{
//		if (check(v))
//			count++;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << count << endl;
//	return 0;
//} //29

////快速排序
//#include <stdio.h>
//void swap(int a[], int i, int j)
//{
//	int t = a[i];
//	a[i] = a[j];
//	a[j] = t;
//}
//int partition(int a[], int p, int r)
//{
//	int i = p;
//	int j = r + 1;
//	int x = a[p];
//	while (1){
//		while (i < r&&a[++i] < x);
//		while (a[--j]>x);
//		if (i >= j)break;
//		swap(a, i, j);
//	}
//	swap(a, p, j); //填空
//	return j;
//}
//void quicksort(int a[], int p, int r)
//{
//	if (p < r){
//		int q = partition(a, p, r);
//		quicksort(a, p, q - 1);
//		quicksort(a, q + 1, r);
//	}
//}
//int main()
//{
//	int i;
//	int a[] = { 5, 13, 6, 24, 2, 8, 19, 27, 6, 12, 1, 17 };
//	int N = 12;
//	quicksort(a, 0, N - 1);
//	for (i = 0; i < N; i++)printf("%d ", a[i]);
//	printf("\n");
//	return 0;
//}

//抽签
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024
int count = 0;
void f(int a[], int k, int m, char b[])
{
	int i, j;
	if (k == N){
		b[M] = 0;
		if (m == 0)
		{
			printf("%s\n", b);
			count++;
		}
		return;
	}
	for (i = 0; i <= a[k]; i++){
		for (j = 0; j < i; j++)
			b[M - m + j] = k + 'A';
		f(a, k + 1, m - i, b);
	}
}
int main()
{
	int a[N] = { 4, 2, 2, 1, 1, 3 };
	char b[BUF];
	f(a, 0, M, b);
	printf("%d\n", count); //101
	return 0;
}