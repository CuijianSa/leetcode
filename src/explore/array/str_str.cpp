#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;

        int i = 0, j = 0;
        for (i = 0; i < haystack.size(); i++) {
            if (j == needle.size()) {
                return i - needle.size();
            }
            if (haystack[i] == needle[j]) {
                j++;
            } else {
                i -= j;
                j = 0;
            }
        }
        if (j == needle.size()) {
            return i - needle.size();
        }
        return -1;
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    cout << s.strStr("hello", "ll") << endl;
    cout << s.strStr("aaaaa", "bba") << endl;
    cout << s.strStr("mississippi", "issip") << endl;
    return 0;
}