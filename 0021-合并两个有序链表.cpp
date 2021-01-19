//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例 1：
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
//
//示例 2：
//输入：l1 = [], l2 = []
//输出：[]

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    ListNode *preHead = new ListNode(-1);

    ListNode *prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == nullptr ? l2 : l1;

    return preHead->next;
}


int main() {

}