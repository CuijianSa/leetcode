
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
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    ListNode *nodeList = createNode();
    nodeList = s.reverseList(nodeList);

    while (nodeList) {
        cout << nodeList->val << " ";
        nodeList = nodeList->next;
    }

    return 0;
}