////熊孩子拜访
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//using namespace std;
//int main() 
//{
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	//1、从前往后进行查找，找到第一个比后面一个数大的位置
//	int index = 1;
//	while (index < n&&v[index - 1] <= v[index])
//	{
//		index++;
//	}
//	if (index == n)
//	{
//		//如果没有则输出0 0
//		cout << 0 << " " << 0 << endl;
//		return 0;
//	}
//	//2、继续向后进行查找，找到第一个比后面一个数小的位置
//	int start = index - 1;
//	while (index < n&&v[index - 1] >= v[index])
//	{
//		index++;
//	}
//	int end = index - 1;
//	cout << v[end] << " " << v[start] << endl;
//	return 0;
//}

////走楼梯
//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//using namespace std;
//long long Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return n;
//
//	long long first = 1;
//	long long second = 1;
//	long long third = 2;
//	while (n > 2)
//	{
//		first = second;
//		second = third;
//		third = first + second;
//		n--;
//	}
//	return third;
//}
//int main() 
//{
//	int n;
//	cin >> n;
//	cout << Fibonacci(n) << endl;
//	return 0;
//}////括号上色//#include <iostream>
//#include <string>
//#include <sstream>
//#include <vector>
//using namespace std;
//typedef long long ll;
//const int MOD = 1e9 + 7, N = 705;
//int f[N][N][3][3];
//int m[N];
//int solution(std::string s) {
//	int n = s.size();
//	vector<int> stk;
//	for (int i = 0; i < n; i++) {//预处理一下括号匹配的位置
//		if (s[i] == '(') stk.push_back(i);
//		else {
//			int u = stk.back();
//			stk.pop_back();
//			m[u] = i;
//			m[i] = u;
//		}
//	}
//	for (int i = 0; i < n; i++) {//状态边界
//		if (m[i] == i + 1) f[i][i + 1][0][1] = f[i][i + 1][0][2] = f[i][i + 1][1][0] = f[i][i + 1][2][0] = 1;
//	}
//	for (int len = 4; len <= n; len += 2) {
//		for (int i = 0, j = i + len - 1; j < n; i++, j++) {
//			if (s[i] != '(' || s[j] != ')') continue;
//			if (m[i] == j) {
//				for (int a = 1; a < 3; a++) {//只枚举需要染色的一端
//					for (int b = 0; b < 3; b++) {
//						if (b == a) continue;//匹配的括号颜色不能相同
//						for (int c = 0; c < 3; c++) {
//							f[i][j][a][0] = (f[i][j][a][0] + f[i + 1][j - 1][b][c]) % MOD;
//							f[i][j][0][a] = (f[i][j][0][a] + f[i + 1][j - 1][c][b]) % MOD;
//						}
//					}
//				}
//			}
//			else {
//				int i1 = m[i], j1 = m[i] + 1;
//				for (int a = 0; a < 3; a++) {
//					for (int b = 0; b < 3; b++) {
//						for (int c = 0; c < 3; c++) {
//							for (int d = 0; d < 3; d++) {
//								if (b == c && b) continue;//相邻括号有颜色不能相同
//								//乘法原理，不用考虑子序列匹配的括号颜色是否相同，相同的话值就是0
//								//这里乘法要加上强转，不然会爆int
//								f[i][j][a][d] = (f[i][j][a][d] + ((ll)f[i][i1][a][b] * f[j1][j][c][d]) % MOD) % MOD;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	int res = 0;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			res = (res + f[0][n - 1][i][j]) % MOD;
//		}
//	}
//	return res;
//}
//int main() {
//	std::string s;
//	std::cin >> s;
//	int result = solution(s);
//	std::cout << result << std::endl;
//	return 0;
//}


//喜水青蛙
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10100;
int f[N], w[N], stones[105];
int main(){
	int L, s, t, m;
	cin >> L >> s >> t >> m;
	for (int i = 1; i <= m; i++)    cin >> stones[i];
	int res = 0;
	if (s == t) {
		for (int i = 1; i <= m; i++) {
			if (stones[i] % s == 0)  res++;
		}
		cout << res << endl;
	}
	else {
		int last = 0;
		sort(stones + 1, stones + m + 1);
		for (int i = 1; i <= m; i++) {
			int diff = min(stones[i] - last, 100);
			last = stones[i];
			stones[i] = stones[i - 1] + diff;
		}
		for (int i = 1; i <= m; i++)   w[stones[i]] = 1;
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		for (int i = s; i <= stones[m] + 10; i++) {
			for (int j = i - t; j <= i - s; j++) {
				if (j < 0)   continue;
				f[i] = min(f[i], f[j] + w[i]);
			}
		}
		res = 100;
		for (int i = stones[m]; i <= stones[m] + 10; i++)  res = min(res, f[i]);
		cout << res << endl;
	}
	return 0;
}