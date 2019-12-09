#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
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
    ListNode *head = createNode();

    head = s.swapPairs(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;

    return 0;
}