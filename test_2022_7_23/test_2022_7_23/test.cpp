//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Bonus {
//public:
//	int func(vector<vector<int>>& board, int x, int y)
//	{
//		if (x == 5 && y == 5)
//			return 0;
//		if (x > 5 || y > 5)
//			return 0;
//		else
//			return max(func(board, x + 1, y) + board[x + 1][y], func(board, x, y + 1) + board[x][y + 1]);
//	}
//	int getMost(vector<vector<int>> board) {
//		int ret = board[0][0] + func(board, 0, 0);
//		return ret;
//	}
//};
//int main()
//{
//	vector<vector<int>> v{
//		{ 1, 2, 3, 4, 5, 6 },
//		{ 1, 2, 3, 4, 5, 6 },
//		{ 1, 2, 3, 4, 5, 6 },
//		{ 1, 2, 3, 4, 5, 6 },
//		{ 1, 2, 3, 4, 5, 6 },
//		{ 1, 2, 3, 4, 5, 6 },
//};
//	cout << Bonus().getMost(v) << endl;
//	return 0;
//}

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	int m = 5, n = 5;
	vector<vector<int>> vv{ 
		{ 0, 1, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0 } };
	vector<vector<int>> view(m, vector<int>(n, 0));
	view[m - 1][n - 1] = 1;
	stack<pair<pair<int, int>, int>> st;
	int arr[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	bool found = false;
	st.push(make_pair(make_pair(m - 1, n - 1), 0)); //0ÉÏ£¬1ÓÒ£¬2ÏÂ£¬3×ó
	while (!st.empty() && !found)
	{
		auto top = st.top();
		st.pop();
		int row = top.first.first, col = top.first.second, dir = top.second;
		while (!found&&dir < 4)
		{
			int nextRow = row + arr[dir][0], nextCol = col + arr[dir][1];
			if (nextRow == 0 && nextCol == 0)
			{
				st.push(make_pair(make_pair(row, col), dir));
				st.push(make_pair(make_pair(nextRow, nextCol), 0));
				found = true;
			}
			else if (nextRow < 0||nextCol <0||nextRow >= m || nextCol >= n)
				dir++;
			else if (!vv[nextRow][nextCol] && !view[nextRow][nextCol])
			{
				view[nextRow][nextCol] = 1;
				st.push(make_pair(make_pair(row, col), dir + 1));
				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else
				dir++;
		}
	}
	while (!st.empty())
	{
		auto top = st.top();
		st.pop();
		cout << "(" << top.first.first << "," << top.first.second << ")" << endl;
	}
	return 0;
}