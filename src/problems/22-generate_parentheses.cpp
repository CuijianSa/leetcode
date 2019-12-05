#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    void backTrack(vector<string> &ans, string cur, int open, int close, int max) {
        if (cur.length() == max * 2) {
            ans.push_back(cur);
            return;
        }

        if (open < max) {
            backTrack(ans, cur + "(", open + 1, close, max);
        }
        if (close < open) {
            backTrack(ans, cur + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
    return 0;

}