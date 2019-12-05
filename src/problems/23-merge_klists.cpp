#include <iostream>
#include <vector>
#include <queue>

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

//    ListNode *mergeKLists(vector<ListNode *> &lists) {
//        ListNode *head = NULL;
//        for (auto l = lists.begin(); l < lists.end(); l++) {
//            head = mergeTwoLists(head, *l);
//        }
//        return head;
//    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0) return nullptr;
        if (size == 1) return lists[0];
        queue<ListNode *> q(deque<ListNode *>(lists.begin(), lists.end()));
        while (q.size() > 1) {
            ListNode *l1 = q.front();
            q.pop();
            ListNode *l2 = q.front();
            q.pop();
            q.push(mergeTwoLists(l1, l2));
        }
        return q.front();
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    vector<ListNode *> list = {createNode(), createNode(), createNode()};

    ListNode *res = s.mergeKLists(list);

    while (res) {
        cout << res->val << "->";
        res = res->next;
    }

    return 0;
}