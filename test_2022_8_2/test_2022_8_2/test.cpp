//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct TreeNode {
//	int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//	int _isBalanced(TreeNode* root)
//	{
//		if (root == nullptr)
//			return 0;
//		int leftHight = _isBalanced(root->left);
//		int rightHight = _isBalanced(root->right);
//		if (leftHight == -1 || rightHight == -1 || abs(rightHight - leftHight) > 1)
//			return -1;
//		else
//			return max(leftHight, rightHight) + 1;
//	}
//	bool isBalanced(TreeNode* root) {
//		return _isBalanced(root) >= 0;
//	}
//};
//
//int main()
//{
//	TreeNode* n1 = new TreeNode(1);
//	TreeNode* n2 = new TreeNode(2);
//	TreeNode* n3 = new TreeNode(2);
//	TreeNode* n4 = new TreeNode(3);
//	TreeNode* n5 = new TreeNode(3);
//	TreeNode* n6 = new TreeNode(4);
//	TreeNode* n7 = new TreeNode(4);
//	n1->left = n2;
//	n1->right = n3;
//	n2->left = n4;
//	n2->right = n5;
//	n4->left = n6;
//	n4->right = n7;
//	cout << Solution().isBalanced(n1) << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//¥Úº“ΩŸ…·
class Solution {
public:
	long long subsequence(int n, vector<int>& array) {
		vector<long long> dp(n);
		dp[0] = max(0, array[0]);
		dp[1] = max(dp[0], (long long)array[1]);
		for (int i = 2; i < n; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + array[i]);
		}
		return dp[n - 1];
	}
};
int main()
{
	vector<int> v{ 2, 3, 4, 5 };
	cout << Solution().subsequence(4, v) << endl;
	return 0;
}
