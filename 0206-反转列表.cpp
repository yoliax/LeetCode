//反转一个单链表。
//
//示例:
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//
//进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ostream &operator<<(ostream &o, ListNode *l) {
    o << "[ ";
    ListNode *t = l;
    while (t) {
        o << t->val << " ";
        t = t->next;
    }
    o << "]";
    return o;
}

ListNode *initList(vector<int> &nums) {
    if (nums.size() < 1)return nullptr;
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for (int i = 1; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

ListNode * reverseList2(ListNode *head){
    ListNode *prev = nullptr, *next = nullptr;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = initList(nums);

    cout << "原始列表：" << head << endl;
    cout << "递归反转列表：" << reverseList(head) << endl;

}