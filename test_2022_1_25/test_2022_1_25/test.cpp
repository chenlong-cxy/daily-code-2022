////垒骰子
//#include <iostream>
//#define MOD 1000000007
//using namespace std;
//int n, m;
//int op[7];
//bool conflict[7][7];
//void init()
//{
//	//骰子对立面
//	op[1] = 4;
//	op[4] = 1;
//	op[2] = 5;
//	op[5] = 2;
//	op[3] = 6;
//	op[6] = 3;
//}
//long long f(int up, int cnt)
//{
//	if (cnt == 0)
//		return 4;
//	long long ans = 0;
//	for (int upp = 1; upp <= 6; upp++)
//	{
//		if (conflict[op[up]][upp])
//			continue;
//		ans = (ans + f(upp, cnt - 1)) % MOD;
//	}
//	return ans;
//}
//int main()
//{
//	init();
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		conflict[x][y] = conflict[y][x] = true;
//	}
//	long long ans = 0;
//	for (int up = 1; up <= 6; up++)
//	{
//		ans = (ans + 4 * f(up, n - 1)) % MOD;
//	}
//	cout << ans << endl;
//	return 0;
//}

////垒骰子
//#include <iostream>
////#include <map>
//#define MOD 1000000007
//using namespace std;
//long long dp[2][7];
//int n, m;
//bool conflict[7][7];
////map<int, int> op;
//int op[7];
//void init()
//{
//	//骰子对立面
//	op[1] = 4;
//	op[4] = 1;
//	op[2] = 5;
//	op[5] = 2;
//	op[3] = 6;
//	op[6] = 3;
//}
//int main()
//{
//	init();
//	//输入处理
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		conflict[a][b] = conflict[b][a] = true;
//	}
//	for (int j = 1; j <= 6; j++)
//	{
//		dp[0][j] = 1;
//	}
//	int cur = 0;
//	for (int level = 2; level <= n; level++)
//	{
//		cur = 1 - cur; //0->1, 1->0
//		for (int j = 1; j <= 6; j++)
//		{
//			dp[cur][j] = 0;
//			for (int i = 1; i <= 6; i++)
//			{
//				if (conflict[j][i])
//					continue;
//				dp[cur][j] = (dp[cur][j] + dp[1 - cur][i]) % MOD;
//			}
//		}
//	}
//	long long sum = 0;
//	for (int k = 1; k <= 6; k++)
//	{
//		sum = (sum + dp[cur][k]) % MOD;
//	}
//	//快速幂求n的4次方
//	long long ans = 1;
//	long long tmp = 4;
//	long long p = n;
//	while (p != 0)
//	{
//		if ((p & 1) == 1)
//			ans = (ans*tmp) % MOD;
//		tmp = (tmp*tmp) % MOD;
//		p >>= 1;
//	}
//	cout << ((sum*ans) % MOD) << endl;
//	return 0;
//}