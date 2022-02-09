////四平方和
//#include <iostream>
//#include <unordered_map>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int N = 0;
//	cin >> N;
//	unordered_map<int, int> um;
//	for (int c = 0; c*c <= N / 2; c++)
//	{
//		for (int d = c; c*c + d*d <= N; d++)
//		{
//			if (um.find(c*c + d*d) == um.end())
//				um[c*c + d*d] = c;
//		}
//	}
//	for (int a = 0; a*a <= N / 4; a++)
//	{
//		for (int b = a; a*a + b*b <= N / 2; b++)
//		{
//			if (um.find(N - a*a - b*b) != um.end())
//			{
//				int c = um[N - a*a - b*b];
//				int d = (int)sqrt(N - a*a - b*b - c*c);
//				cout << a << " " << b << " " << c << " " << d << endl;
//				return 0;
//			}
//		}
//	}
//	return 0;
//}

////四平方和test
//#include <iostream>
//#include <unordered_map>
//#include <cmath>
//using namespace std;
//int main()
//{
//	for (int x = 1; x < 100000; x++)
//	{
//		for (int y = 1; y < 100000; y++)
//		{
//			if (x*x + y*y == 1000)
//				cout << x << " " << y << endl;
//		}
//	}
//	return 0;
//}

////交换瓶子
//#include <iostream>
//#include <vector>
//using namespace std;
//size_t pos(vector<int>& v, size_t x)
//{
//	for (size_t i = x + 1; i < v.size(); i++)
//	{
//		if (v[i] == x)
//			return i;
//	}
//	return -1;
//}
//void swap(vector<int>& v, size_t i, size_t j)
//{
//	size_t tmp = v[i];
//	v[i] = v[j];
//	v[j] = tmp;
//}
//int main()
//{
//	int N = 0;
//	cin >> N;
//	vector<int> v;
//	v.resize(N + 1);
//	v[0] = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		int data = 0;
//		cin >> data;
//		v[i] = data;
//	}
//	int ans = 0;
//	for (size_t i = 1; i < v.size(); i++)
//	{
//		if (v[i] != i)
//		{
//			swap(v, i, pos(v, i));
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//等差素数列
#include <iostream>
#include <unordered_set>
#include <vector>
#define N 5000
using namespace std;
bool Isprime(int num)
{
	for (int i = 2; i < num / 2; i++)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}
int f(vector<int>& v, unordered_set<int>& us)
{
	for (int i = 0; i < N; i++) //枚举首项
	{
		int first = v[i];
		for (int delta = 1; delta < v[N - 1] - first; delta++) //枚举公差
		{
			int m = first;
			int count = 0;
			for (count = 0; count < 9; count++)
			{
				m += delta;
				if (us.find(m) == us.end()) //不是素数
					break;
				if (m>v[N - 1]) //超出已计算的素数范围
					break;
			}
			if (count == 9)
				return delta;
		}
	}
	return -1;
}
int main()
{
	unordered_set<int> us;
	vector<int> v;
	v.resize(N);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	us.insert(1);
	us.insert(2);
	us.insert(3);
	int count = 3;
	int num = 5;
	while (count < N)
	{
		if (Isprime(num))
		{
			v[count] = num;
			us.insert(num);
			count++;
		}
		num++;
	}
	cout << f(v, us) << endl;
	return 0;
}
