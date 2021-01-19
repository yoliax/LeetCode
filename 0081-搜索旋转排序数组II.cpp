//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//( 例如，数组[0,0,1,2,2,5,6]可能变为[2,5,6,0,0,1,2])。
//
//编写一个函数来判断给定的目标值是否存在于数组中。若存在返回true，否则返回false。
//
//示例1:
//
//输入: nums = [2,5,6,0,0,1,2], target = 0
//输出: true
//示例2:
//
//输入: nums = [2,5,6,0,0,1,2], target = 3
//输出: false
//进阶:
//
//这是 搜索旋转排序数组的延伸题目，本题中的nums 可能包含重复元素。
//这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

#include <vector>
#include <iostream>

using namespace std;

bool search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[start] == nums[mid]) {
            ++start;
        } else if (nums[mid] <= nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << search(nums, 0) << endl;

    vector<int> nums2 = {2,5,6,0,0,1,2};
    cout << search(nums2, 3) << endl;
}