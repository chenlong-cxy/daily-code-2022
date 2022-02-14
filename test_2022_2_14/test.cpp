//分巧克力
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, K;
	cin>>N>>K;
	vector<int> h, w;
	h.resize(N);
	w.resize(N);
	for(int i = 0;i < N;i++)
	{
		cin>>h[i]>>w[i];
	}
	
	for(int len = 100000; len >= 1;len--)
	{
		int count = 0;
		for(int i = 0;i < N;i++)
		{
			count += (h[i]/len)*(w[i]/len);
		}
		if(count >= K)
		{
			cout<<len<<endl;
			return 0;
		}
	}
	return 0;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, K;
	cin>>N>>K;
	vector<int> h, w;
	h.resize(N);
	w.resize(N);
	for(int i = 0;i < N;i++)
	{
		cin>>h[i]>>w[i];
	}
	
	int left = 1, right = 100000;
	int ans = 0;
	while(left <= right)
	{
		int mid = left + (right-left)/2;
		int count = 0;
		for(int i = 0;i < N;i++)
		{
			count += (h[i]/mid)*(w[i]/mid);
		}
		if(count >= K)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
*/

//K倍区间
/*
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int N, K;
	cin>>N>>K;
	vector<int> s; //前缀和 
	s.resize(N + 1);
	map<int, int> cnt;
	cnt[0] = 1; //s[0]=0
	for(int i = 1;i <= N;i++)
	{
		int data = 0;
		cin>>data;
		s[i] = (s[i-1] + data)%K;
		cnt[s[i]]++;
	}
	long long ans = 0;
	for(int i = 0;i < K;i++)
	{
		ans += (long long)cnt[i]*(cnt[i] - 1)/2; //m(m-1)/2
	}
	cout<<ans<<endl;
	return 0;
}
*/

//明码
#include <iostream>
using namespace std;
void toBinaryStr(int num, string& str)
{
	for(int i = 0;i < 8;i++)
	{
		if(((num>>i)&1) == 1)
			str[8-i-1] = '1';
	}
	/* 
	if(num >= 0)
	{
		for(int i = 0;i < 7;i++)
		{
			if(((num>>i)&1) == 1)
				str[8-i-1] = '1';
		}
	}
	else
	{
		str[0] = '1';
		for(int i = 0;i < 7;i++)
		{
			if(((128+num)>>i) == 1)
				str[8-i-1] = '1';
		}	
	}*/
}
int main()
{
	for(int i = 0;i < 10;i++) //10个汉字 
	{
		for(int j = 0;j < 16;j++) //每个汉字16行
		{
			int x, y;
			cin>>x>>y; //每行由2个字节组成
			string xx = "--------", yy = "--------";
			toBinaryStr(x, xx);
			toBinaryStr(y, yy);
			cout<<xx + yy<<endl;
		} 
		cout<<"=================="<<endl;
	}
	long long ans = 9;
	for(int k = 0;k < 9;k++)
	{
		ans *= 9; 
	} 
	cout<<ans<<endl;
	return 0;
}











