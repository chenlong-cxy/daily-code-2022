////日期问题
//#include <iostream>
//#include <string>
//#include <set>
//using namespace std;
//bool IsLeapYear(int year)
//{
//	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//string f(int year, int month, int day)
//{
//	if (year >= 0 && year <= 59)
//		year += 2000;
//	else
//		year += 1900;
//
//	if (month <1 || month > 12)
//		return "";
//	if (day < 1 || day > 31)
//		return "";
//
//	switch (month)
//	{
//	case 2:
//		if (IsLeapYear(year) && day > 29)
//			return "";
//		else if (day > 28)
//			return "";
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		if (day > 30)
//			return "";
//		break;
//	default:
//		break;
//	}
//	string y, m, d;
//	y = to_string(year);
//	m = to_string(month);
//	d = to_string(day);
//	if (month < 10)
//		m = "0" + m;
//	if (day < 10)
//		d = "0" + d;
//	return y + "-" + m + "-" + d;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	int a = (s[0] - '0') * 10 + (s[1] - '0');
//	int b = (s[3] - '0') * 10 + (s[4] - '0');
//	int c = (s[6] - '0') * 10 + (s[7] - '0');
//	string ret1 = f(a, b, c);
//	string ret2 = f(c, a, b);
//	string ret3 = f(c, b, a);
//	set<string> ans;
//	if (ret1 != "")
//		ans.insert(ret1);
//	if (ret2 != "")
//		ans.insert(ret2);
//	if (ret3 != "")
//		ans.insert(ret3);
//	set<string>::iterator it = ans.begin();
//	while (it != ans.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	return 0;
//}

////包子凑数
//#include <iostream>
//#include <vector>
//using namespace std;
//int gcd(int a, int b)
//{
//	if (b == 0)
//		return a;
//	else
//		return gcd(b, a%b);
//}
//int main()
//{
//	int N = 0;
//	cin >> N;
//	vector<int> v;
//	v.resize(N + 1);
//	int g = 0;
//	vector<bool> table;
//	table.resize(10000, false);
//	table[0] = true;
//	for (int i = 1; i <= N; i++)
//	{
//		int num = 0;
//		cin >> num;
//		v[i] = num;
//		if (i == 1) //初始化最大公约数
//			g = v[i];
//		else
//			g = gcd(v[i], g);
//
//		for (int j = 0; j < 10000; j++)
//		{
//			if (table[j] == true && j + v[i] < 10000)
//				table[j + v[i]] = true;
//		}
//	}
//	if (g != 1)
//	{
//		cout << "INF" << endl;
//		return 0;
//	}
//	int ans = 0;
//	for (int i = 0; i < 10000; i++)
//	{
//		if (table[i] == false)
//			ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}
