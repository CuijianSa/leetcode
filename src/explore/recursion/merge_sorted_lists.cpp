#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createNode() {
    int n = 5;
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    for (int i = 0; i < n; i++) {
        ListNode *node = new ListNode(i + 1);
        if (head) {
            cur->next = node;
            cur = node;
        } else {
            head = cur = node;
        }
    }
    return head;
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (nullptr == l1) return l2;
        if (nullptr == l2) return l1;
        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    ListNode *list = s.mergeTwoLists(createNode(), createNode());

    while (list) {
        cout << list->val << "->";
        list = list->next;
    }

    return 0;
}