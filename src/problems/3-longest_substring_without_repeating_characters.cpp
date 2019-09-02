//Longest Substring Without Repeating Characters
//
//Given a string, find the length of the longest substring without repeating characters.

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0, i = 0, j = 0;
        set<char> set;

        while (i < n && j < n) {
            // 在s[i,j] 中寻找最长子串
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j++]);
                ans = ans > (j - i) ? ans : (j - i);
            } else {
                set.erase(s[i++]);
            }
        }
        return ans;
    }


};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("cdd") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}