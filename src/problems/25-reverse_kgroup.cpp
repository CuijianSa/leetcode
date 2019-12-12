#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
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
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int d = 0;

        ListNode *node = head;
        while (node) {
            if (++d >= k) break;
            node = node->next;
        }

        if (d < k) return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;

        for (int i = 0; i < k; ++i) {
            node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }

private:
    ListNode *m_last;

};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *head = createNode();
    head = s.reverseKGroup(head, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}