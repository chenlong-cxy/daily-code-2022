//最大比例
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;

LL my_gcd(LL a, LL b)
{
	if (b == 0)
		return a;
	return my_gcd(b, a%b);
}

void init(map<LL, map<LL, LL>>& ex, map<LL, map<LL, LL>>& log)
{
	for (LL i = 2; i < 1e6; i++)
	{
		LL cur = i*i;
		LL pow = 2;
		while (cur < 1e12)
		{
			ex[cur][pow] = i; //cur开pow次方等于i
			log[cur][i] = pow; //cur是i的pow次方
			pow++;
			cur *= i;
		}
	}
}

LL extract(map<LL, map<LL, LL>>& ex, LL x, LL pow) //x开pow次方是多少
{
	if (pow == 1) //开1次方是本身
		return x;
	if (x == 1) //1开任意次方都是1
		return 1;
	if (ex[x].find(pow) != ex[x].end()) //x可以开pow的整数次方
		return ex[x][pow];
	else
		return -1;
}

LL log(map<LL, map<LL, LL>>& log, LL x, LL y) //x是y的多少次方
{
	if (x == y)
		return 1;
	if (log[x].find(y) != log[x].end())
		return log[x][y];
	else
		return -1;
}

int main()
{
	map<LL, map<LL, LL>> all_ex;
	map<LL, map<LL, LL>> all_log;
	init(all_ex, all_log);
	pair<LL, LL> ans;
	//处理输入
	int N = 0;
	cin >> N;
	vector<LL> v;
	for (int i = 0; i < N; i++)
	{
		LL data = 0;
		cin >> data;
		v.push_back(data);
	}
	//计算相邻比值
	sort(v.begin(), v.end());
	vector<pair<LL, LL>> ratios; //存储比值
	for (int i = 0; i < N - 1; i++)
	{
		if (v[i] != v[i + 1]) //去重
		{
			LL gcd = my_gcd(v[i], v[i + 1]);
			LL x = v[i] / gcd;
			LL y = v[i + 1] / gcd;
			ratios.push_back(make_pair(y, x));
		}
	}
	//对第一个比值进行开方
	for (LL pow = 1; pow <= 40; pow++)
	{
		pair<LL, LL> ra = ratios[0];
		LL x = extract(all_ex, ra.first, pow);
		LL y = extract(all_ex, ra.second, pow);
		if (x == -1 || y == -1) //开不出
			continue;
		size_t i = 0;
		for (i = 0; i < ratios.size(); i++)
		{
			LL px = log(all_log, ratios[i].first, x);
			LL py = log(all_log, ratios[i].second, y);
			if (ratios[i].second == 1 && y == 1)
				py = px;
			if (px == -1 || py == -1 || px != py)
				break;
		}
		if (i == ratios.size())
		{
			ans = make_pair(x, y);
			break;
		}
	}
	cout << ans.first << "/" << ans.second << endl;
	return 0;
}//549755813888 524288 2