//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//#include <string>
//using namespace std;
//int main()
//{
//	unordered_map<char, int> um{ { 'A', 2 }, { 'B', 2 }, { 'C', 2 },
//	{ 'D', 3 }, { 'E', 3 }, { 'F', 3 },
//	{ 'G', 4 }, { 'H', 4 }, { 'I', 4 },
//	{ 'J', 5 }, { 'K', 5 }, { 'L', 5 },
//	{ 'M', 6 }, { 'N', 6 }, { 'O', 6 },
//	{ 'P', 7 }, { 'Q', 7 }, { 'R', 7 }, { 'S', 7 },
//	{ 'T', 8 }, { 'U', 8 }, { 'V', 8 },
//	{ 'W', 9 }, { 'X', 9 }, { 'Y', 9 }, { 'Z', 9 } };
//	int n = 0;
//	while (cin >> n)
//	{
//		unordered_set<string> us;
//		for (int i = 0; i < n; i++)
//		{
//			string s;
//			int count = 0;
//			cin >> s;
//			string number = "";
//			for (char ch : s)
//			{
//				if (ch >= '0'&&ch <= '9')
//				{
//					number += ch;
//					count++;
//					if (count == 3)
//						number += "-";
//				}
//				else if (ch >= 'A'&&ch <= 'Z')
//				{
//					auto it = um.find(ch);
//					number += (it->second + '0');
//					count++;
//					if (count == 3)
//						number += "-";
//				}
//			}
//			us.insert(number);
//		}
//		for (auto e : us)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<int> v;
//void func(int n, int m, int cur, int sum)
//{
//	if (sum > m)
//		return;
//	if (sum == m)
//	{
//		for (auto e : v)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}
//	for (int i = cur; i <= n; i++)
//	{
//		if (i <= m - sum)
//		{
//			v.push_back(i);
//			func(n, m, i + 1, sum + i);
//			v.pop_back();
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	func(n, m, 1, 0);
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <set>
//using namespace std;
//
//string func(string s2, string s1)
//{
//	string s = "";
//	for (char ch : s2)
//	{
//		if (ch >= '0'&&ch <= '9')
//			s += ch;
//		else if (ch == '-')   //字符 '-' 忽略
//			continue;
//		else
//		{
//			s += s1[ch - 'A'];
//		}
//	}
//	string ret1 = s.substr(0, 3);
//	string ret2 = s.substr(3, 4);
//	s = "";
//	s += ret1;
//	s += "-";
//	s += ret2;
//	return s;
//}
//
//int main()
//{
//	string s1 = "22233344455566677778889999";
//	int n;
//	while (cin >> n)
//	{
//		set <string> data;
//		for (int i = 0; i < n; i++)
//		{
//			string a;
//			cin >> a;
//			string s = func(a, s1);
//			data.insert(s);
//		}
//		for (auto &e : data)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}


//带分数
//存在深拷贝（效率太慢）
//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//int main()
//{
//	int N = 0;
//	cin >> N;
//	int count = 0;
//	string s = "123456789";
//	do{
//		for (int i = 1; i <= 7; i++)
//		{
//			string a = s.substr(0, i);
//			int ai = stoi(a);
//			if (ai >= N)
//				continue;
//			for (int j = 1; j <= 9 - i - 1; j++)
//			{
//				string b = s.substr(i, j);
//				int bi = stoi(b);
//				string c = s.substr(i + j);
//				int ci = stoi(c);
//				if (bi%ci == 0 && ai + bi / ci == N)
//					count++;
//			}
//		}
//	} while (next_permutation(s.begin(), s.end()));
//	cout << count << endl;
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//int func(string& s, int pos, int len)
//{
//	int ret = 0;
//	int t = 1;
//	for (int i = pos + len - 1; i >= pos; i--)
//	{
//		ret += (s[i] - '0')*t;
//		t *= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int N = 0;
//	cin >> N;
//	int count = 0;
//	string s = "123456789";
//	do{
//		for (int i = 1; i <= 7; i++)
//		{
//			int a = func(s, 0, i);
//			if (a >= N)
//				continue;
//			for (int j = 1; j <= 9 - i - 1; j++)
//			{
//				int b = func(s, i, j);
//				int c = func(s, i + j, 9 - i - j);
//				if (b%c == 0 && a + b / c == N)
//					count++;
//			}
//		}
//	} while (next_permutation(s.begin(), s.end()));
//	cout << count << endl;
//	return 0;
//}

////连号区间数
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//vector<int> v;
//bool func(int pos, int num)
//{
//	int max = v[pos], min = v[pos];
//	for (int i = 0; i < num; i++)
//	{
//		if (v[pos + i]>max)
//			max = v[pos + i];
//		if (v[pos + i] < min)
//			min = v[pos + i];
//	}
//	if (max - min == num - 1)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	int N = 0;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int data = 0;
//		cin >> data;
//		v.push_back(data);
//	}
//	int ret = N + 1;
//	for (int num = 2; num <= N - 1; num++)
//	{
//		for (int pos = 0; pos < N - num + 1; pos++)
//		{
//			if (func(pos, num))
//				ret++;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}