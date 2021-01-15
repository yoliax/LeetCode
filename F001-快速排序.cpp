#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int> &nums, int l, int r) {
    if (l + 1 >= r)
        return;
    int first = l, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quickSort(nums, l, first);
    quickSort(nums, first + 1, r);
}

int main() {
    vector<int> nums = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    quickSort(nums, 0, nums.size());
    for(auto x: nums){
        cout << x << endl;
    }
}
