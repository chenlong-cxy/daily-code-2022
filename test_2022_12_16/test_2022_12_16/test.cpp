#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int binarySearch(vector<int>& nums, int target, bool lower)
	{
		int left = 0, right = nums.size() - 1, ans = nums.size();
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if ((nums[mid] > target) || (lower&&nums[mid] >= target))
			{
				right = mid - 1;
				ans = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return ans;
	}
	int search(vector<int>& nums, int target) {
		int leftIndex = binarySearch(nums, target, true);
		int rightIndex = binarySearch(nums, target, false) - 1;
		if (leftIndex <= rightIndex&&rightIndex < nums.size())
			return rightIndex - leftIndex + 1;
		return 0;
	}
};
int main()
{
	vector<int> v{ 5, 7, 7, 8, 8, 10 };
	cout << Solution().search(v, 8) << endl;
	return 0;
}
