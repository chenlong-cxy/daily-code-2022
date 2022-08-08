#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int func(vector<vector<char>>& v, vector<vector<bool>>& flag, int x, int y)
{
	int m = v.size(), n = v[0].size();
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	flag[x][y] = true;
	int count = 0;
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();
		x = front.first, y = front.second;
		if (x - 1 >= 0 && flag[x - 1][y] == false && v[x - 1][y] == '.')
		{
			q.push(make_pair(x - 1, y));
			flag[x - 1][y] = true;
		}
		if (x + 1 < m&&flag[x + 1][y] == false && v[x + 1][y] == '.')
		{
			q.push(make_pair(x + 1, y));
			flag[x + 1][y] = true;
		}
		if (y - 1 >= 0 && flag[x][y - 1] == false && v[x][y - 1] == '.')
		{
			q.push(make_pair(x, y - 1));
			flag[x][y - 1] = true;
		}
		if (y + 1 < n&&flag[x][y + 1] == false && v[x][y + 1] == '.')
		{
			q.push(make_pair(x, y + 1));
			flag[x][y + 1] = true;
		}
		count++;
	}
	return count;
}
int main()
{
	int m, n;
	cin >> m >> n;
	//while (cin >> m >> n)
	//{
		vector<vector<char>> v(m, vector<char>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
			}
		}
		int max = 0;
		vector<vector<bool>> flag(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[i][j] == '.'&&flag[i][j] == false)
				{
					int count = func(v, flag, i, j);
					if (count > max)
						max = count;
				}
			}
		}
		cout << max << endl;
	//}
	return 0;
}