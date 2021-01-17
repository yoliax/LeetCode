//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为O(log n)的算法解决此问题吗？
//
//
//示例 1：
//
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4]
//示例2：
//
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1]
//示例 3：
//
//输入：nums = [], target = 0
//输出：[-1,-1]
//

#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> &nums, int target, bool lower) {
    int left = 0, right = nums.size() - 1, ans = nums.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (lower && nums[mid] >= target)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}


vector<int> searchRange(vector<int> &nums, int target) {
    int leftIdx = binarySearch(nums, target, true);
    int rightIdx = binarySearch(nums, target, false) - 1;
    if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
        return {leftIdx, rightIdx};
    }
    return {-1, -1};
}

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 10};
    vector<int> res = searchRange(nums1, 8);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;

    vector<int> nums2 = {5,7,7,8,8,10};
    res = searchRange(nums2, 6);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;

    vector<int> nums3 = {};
    res = searchRange(nums3, 0);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
}