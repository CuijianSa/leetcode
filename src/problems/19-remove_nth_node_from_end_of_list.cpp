#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //c_p = c_p + n;
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *c = head, *p = head;
        while(n-- > 0) {
            c = c->next;
        }
        if(!c) {
            return head->next;
        }
        while (c->next) {
            c = c->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
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

    ListNode *n = s.removeNthFromEnd(head, 1);

    while(n) {
        cout<<n->val<<endl;
        n = n->next;
    }
    return 0;
}