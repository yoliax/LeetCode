//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//示例 2:
//
//输入: 1->2->2->1
//输出: true
//进阶：
//你能否用O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

#include <vector>
using namespace std;

bool isPalindrome(ListNode *head) {
    vector<int> vals;
    while (head != nullptr) {
        vals.emplace_back(head->val);
        head = head->next;
    }
    for (int i = 0, j = (int) vals.size() - 1; i < j; ++i, --j) {
        if (vals[i] != vals[j]) {
            return false;
        }
    }
    return true;
}