//乘积尾零
/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	vector<int> v{5650,4542,3554,473,946,4114,3871,9073,90,4329,
	2758,7949,6113,5659,5245,7432,3051,4434,6704,3594,
	9937,1173,6866,3397,4759,7557,3070,2287,1453,9899,
	1486,5722,3135,1170,4014,5510,5120,729,2880,9019,
	2049,698,4582,4346,4427,646,9742,7340,1230,7683,
	5693,7015,6887,7381,4172,4341,2909,2027,7355,5649,
	6701,6645,1671,5978,2704,9926,295,3125,3878,6785,
	2066,4247,4800,1578,6652,4616,1113,6205,3264,2915,
	3966,5291,2904,1285,2193,1428,2265,8730,9436,7074,
	689,5510,8243,6114,337,4096,8199,7313,3685,211};
	int cnt2 = 0, cnt5 = 0;
	for(int i = 0;i < v.size();i++)
	{
		int data = v[i];
		while(data%2 == 0)
		{
			cnt2++;
			data /= 2;
		}
		while(data%5 == 0)
		{
			cnt5++;
			data /= 5;
		}
	}
	cout<<min(cnt2, cnt5)<<endl;
	return 0;
} 
*/

//测试次数
/* 
#include <iostream>
#include <climits>
using namespace std;
const int N = 1000;
int main()
{
	int f1[N+1], f2[N+1], f3[N+1]; //1、2、3部手机测n层楼所需最多的次数
	f1[0] = f2[0] = f3[0] = 0;
	//1部手机测n层楼所需最多的次数
	for(int i = 1;i <= N;i++)
	{
		f1[i] = i;
	} 
	//2部手机测n层楼所需最多的次数
	for(int i = 1;i <= N;i++)
	{
		int ans = INT_MAX;
		for(int j = 1;j <= i;j++) //第一部手机从第j层扔下 
		{
			int Max = 1 + max(f2[j-1], f1[i-j]); //第一部手机每坏f2[j-1]，坏了f1[i-j] 
			if(Max < ans)
				ans = Max;
		}
		f2[i] = ans;
	}
	//3部手机测n层楼所需最多的次数
	for(int i = 1;i <= N;i++)
	{
		int ans = INT_MAX;
		for(int j = 1;j <= i;j++) //第一部手机从第j层扔下 
		{
			int Max = 1 + max(f3[j-1], f2[i-j]); //第一部手机每坏f3[j-1]，坏了f2[i-j] 
			if(Max < ans)
				ans = Max;
		}
		f3[i] = ans;
	}
	cout<<f3[N]<<endl;
	return 0;
} 
*/

//递增三元组
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0;
	cin>>n;
	int a[n], b[n], c[n];
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i < n;i++)
	{
		cin>>b[i];
	}
	for(int i = 0;i < n;i++)
	{
		cin>>c[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	int p = 0, q = 0;
	long long ans = 0;
	for(int i = 0;i < n;i++)
	{
		while(p < n&&a[p] < b[i]) p++;
		while(q < n&&b[i] >= c[q]) q++;
		ans += (long long)p*(n-q); 
	}
	cout<<ans<<endl;
	return 0;
} 















