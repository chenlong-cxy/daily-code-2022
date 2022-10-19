//最长回文子串
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int MaxLen = 1;
		int start = 0;
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = true;
		}
		for (int len = 2; len <= n; len++)
		{
			for (int i = 0; i < n; i++)
			{
				int j = i + len - 1;
				if (j >= n)
					break;
				if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1]))
				{
					dp[i][j] = true;
					if (len > MaxLen)
					{
						MaxLen = len;
						start = i;
					}
				}
			}
		}
		return s.substr(start, MaxLen);
	}
};
int main()
{
	cout << Solution().longestPalindrome("bb") << endl;
	return 0;
}