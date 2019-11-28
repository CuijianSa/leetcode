#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    char getPair(char c) {
        if (c == '}') return '{';
        if (c == ']') return '[';
        if (c == ')') return '(';
        return 0;
    }

    bool isValid(string s) {
        stack<char> st;
        if (s.empty()) return true;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == getPair(s[i])) {
                    st.pop();
                } else {
                    return false;
                }

            }
        }

        return st.size() == 0 ? true : false;
    }

};


int main(int argc, char *argv[]) {
    Solution s;

    cout << s.isValid("]") << endl;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    return 0;
}