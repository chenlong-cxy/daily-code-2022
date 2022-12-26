//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
//	{
//		int rowSize = board.size(), colSize = board[0].size();
//		if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
//			return false;
//		if (board[i][j] != word[k])
//			return false;
//		board[i][j] = '\0';
//		bool ret = dfs(board, word, i + 1, j, k + 1) ||
//			dfs(board, word, i - 1, j, k + 1) ||
//			dfs(board, word, i, j + 1, k + 1) ||
//			dfs(board, word, i, j - 1, k + 1);
//		board[i][j] = word[k];
//		return ret;
//	}
//	bool exist(vector<vector<char>>& board, string word) {
//		if (board.size() == 0)
//			return false;
//		int rowSize = board.size(), colSize = board[0].size();
//		for (int i = 0; i < rowSize; i++)
//		{
//			for (int j = 0; j < colSize; j++)
//			{
//				if (dfs(board, word, i, j, 0))
//					return true;
//			}
//		}
//		return false;
//	}
//};
//int main()
//{
//	vector<vector<char>> board = { 
//		{ 'A', 'B', 'C', 'E' },
//		{ 'S', 'F', 'C', 'S' }, 
//		{ 'A', 'D', 'E', 'E' } };
//	string word = "ABCCED";
//	cout << Solution().exist(board, word) << endl;
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		return dfs(0, 0, 0, 0, visited, m, n, k);
	}
private:
	int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
		if (i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
		visited[i][j] = true;
		return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
			dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
	}
};

int main()
{
	cout << Solution().movingCount(38, 15, 9) << endl;
	return 0;
}