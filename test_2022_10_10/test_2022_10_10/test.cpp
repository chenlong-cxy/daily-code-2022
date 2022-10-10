//ËÑË÷²åÈëÎ»ÖÃ
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (target > nums[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};
int main()
{
	vector<int> v = { 1, 3, 5, 6 };
	cout << Solution().searchInsert(v, 7) << endl;
	return 0;
}