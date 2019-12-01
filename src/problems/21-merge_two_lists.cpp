#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
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

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *l1 = createNode();
    ListNode *l2 = createNode();

    ListNode *res = s.mergeTwoLists(l1, l2);

    while (res) {
        cout << res->val << "->";
        res = res->next;
    }
    return 0;
}