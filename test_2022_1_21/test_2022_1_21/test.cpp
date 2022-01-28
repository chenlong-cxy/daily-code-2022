////µØ¹¬È¡±¦
//#include <iostream>
//#include <vector>
//using namespace std;
//const int MOD = 1000000007;
//int n, m, k;
//int data[50][50];
//long long ans;
//void dfs(int x, int y, int max, int cnt)
//{
//	if (x == n || y == m)
//		return;
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1)
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans++;
//		}
//	}
//	if (cur > max&&cnt < k)
//	{
//		dfs(x, y + 1, cur, cnt + 1);
//		dfs(x + 1, y, cur, cnt + 1);
//	}
//	dfs(x, y + 1, max, cnt);
//	dfs(x + 1, y, max, cnt);
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &data[i][j]);
//		}
//	}
//	dfs(0, 0, -1, 0);
//	cout << ans % MOD << endl;
//	return 0;
//}

////µØ¹¬È¡±¦
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//const int MOD = 1000000007;
//int n, m, k;
//int data[50][50];
//int cache[50][50][13][12];
//long long dfs(int x, int y, int max, int cnt)
//{
//	if (x == n || y == m)
//		return 0;
//	if (cache[x][y][max + 1][cnt] != -1)
//		return cache[x][y][max + 1][cnt];
//
//	long long ans = 0;
//	int cur = data[x][y];
//	if (x == n - 1 && y == m - 1)
//	{
//		if (cnt == k || (cnt == k - 1 && cur > max))
//		{
//			ans++;
//			if (ans > MOD)
//				ans %= MOD;
//		}
//		return ans;
//	}
//	if (cur > max&&cnt < k)
//	{
//		ans += dfs(x, y + 1, cur, cnt + 1);
//		ans += dfs(x + 1, y, cur, cnt + 1);
//	}
//	ans += dfs(x, y + 1, max, cnt);
//	ans += dfs(x + 1, y, max, cnt);
//	return ans;
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &data[i][j]);
//		}
//	}
//	memset(cache, -1, sizeof(cache));
//	long long ret = dfs(0, 0, -1, 0);
//	cout << ret % MOD << endl;
//	return 0;
//}

////ÐÇÏµÕ¨µ¯
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> MonthDay{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year = 2014, month = 11, day = 9;
//	for (int i = 0; i < 1000; i++)
//	{
//		day++;
//		if (month == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			{
//				if (day > 29)
//				{
//					day = 1;
//					month++;
//					if (month > 12)
//					{
//						year++;
//						month = 1;
//					}
//				}
//			}
//			else
//			{
//				if (day > 28)
//				{
//					day = 1;
//					month++;
//					if (month > 12)
//					{
//						year++;
//						month = 1;
//					}
//				}
//			}
//		}
//		else if (day > MonthDay[month])
//		{
//			day = 1;
//			month++;
//			if (month > 12)
//			{
//				year++;
//				month = 1;
//			}
//		}
//	}
//	cout << year << "-" << month << "-" << day << endl;
//	return 0;
//}//2017-08-05

////ÈýÑòÏ×Èð
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool check(vector<int>& v)
//{
//	int num1 = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
//	int num2 = 1000 + v[4] * 100 + v[5] * 10 + v[1];
//	int num3 = 10000 + v[4] * 1000 + v[2] * 100 + v[1] * 10 + v[6];
//	if (num1 + num2 == num3)
//		return true;
//	return false;
//}
//int main()
//{
//	//vector<int> v{ 9, 5, 6, 7, 0, 8, 2, 3, 4 }; //abcdfgi
//	vector<int> v{ 0, 2, 3, 4, 5, 6, 7, 8, 9 }; //abcdfgi
//	do
//	{
//		if (check(v))
//		{
//			cout << v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3] << endl;
//			cout << 1000 + v[4] * 100 + v[5] * 10 + v[1] << endl;
//			cout << 10000 + v[4] * 1000 + v[2] * 100 + v[1] * 10 + v[6] << endl;
//			cout << endl;
//		}
//	} while (next_permutation(v.begin(), v.end()));
//	return 0;
//}//1085