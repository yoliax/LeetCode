//给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1必须小于index2。
//
//说明:
//
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
//示例:
//
//输入: numbers = [2, 7, 11, 15], target = 9
//输出: [1,2]
//解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum = 0;
    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target)
            break;
        else if (sum < target)
            ++l;
        else
            --r;
    }
    return {l + 1, r + 1};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> res = twoSum(numbers, 9);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}