////��������
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int vis[10];
//int arr[5][6];
//int ans;
//void init()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 6; j++)
//			arr[i][j] = -10;
//	}
//}
//bool check(int x, int y)
//{
//	for (int i = x - 1; i <= x + 1; i++)
//	{
//		for (int j = y - 1; j <= y + 1; j++)
//		{
//			if (abs(arr[i][j] - arr[x][y]) == 1)
//				return false;
//		}
//	}
//	return true;
//}
//void f(int x, int y)
//{
//	if (x == 3 && y == 4)
//	{
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (vis[i] == 0) //û�б��ù�
//		{
//			arr[x][y] = i;
//			if (!check(x, y)) //���Ϸ�
//			{
//				arr[x][y] = -10; //�û�-10
//				continue; //������һ����
//			}
//			vis[i] = 1; //���Ϊ�ù�
//			if (y == 4) //�����Ѿ�������
//				f(x + 1, 1);
//			else
//				f(x, y + 1);
//			//����
//			arr[x][y] = -10;
//			vis[i] = 0;
//		}
//	}
//}
//int main()
//{
//	init();
//	f(1, 2);
//	cout << ans << endl;
//	return 0;
//}

////����Ʊ
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//void dfs(int arr[3][4], int x, int y)
//{
//	if (x - 1 >= 0 && arr[x - 1][y] == 1)
//	{
//		arr[x - 1][y] = 0;
//		dfs(arr, x - 1, y);
//	}
//	if (x + 1 <= 2 && arr[x + 1][y] == 1)
//	{
//		arr[x + 1][y] = 0;
//		dfs(arr, x + 1, y);
//	}
//	if (y - 1 >= 0 && arr[x][y - 1] == 1)
//	{
//		arr[x][y - 1] = 0;
//		dfs(arr, x, y - 1);
//	}
//	if (y + 1 <= 3 && arr[x][y + 1] == 1)
//	{
//		arr[x][y + 1] = 0;
//		dfs(arr, x, y + 1);
//	}
//}
//bool check(vector<int>& v)
//{
//	int arr[3][4];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			arr[i][j] = v[i * 4 + j];
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	int count = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (arr[i][j] == 1)
//			{
//				dfs(arr, i, j);
//				count++;
//			}
//		}
//	}
//	if (count == 1)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	vector<int> v{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
//	int ans = 0;
//	do
//	{
//		if (check(v))
//			ans++;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << ans << endl;
//	return 0;
//}
