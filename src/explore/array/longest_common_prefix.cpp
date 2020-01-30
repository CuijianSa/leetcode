#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        string prefix = strs[0];
        int preLen = strs[0].length();

        for (auto it = strs.begin(); it != strs.end(); it++) {
            for (int i = 0; i < preLen; i++) {
                if (prefix[i] && (*it)[i] && prefix[i] == (*it)[i]) {
                    continue;
                } else {
                    preLen = i;
                    break;
                }
            }
        }
        return prefix.substr(0, preLen);
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<string> input1 = {"flower", "flow", "flight"};
    vector<string> input2 = {"dog", "racecar", "car"};
    cout << s.longestCommonPrefix(input1) << endl;
    cout << s.longestCommonPrefix(input2) << endl;

    return 0;
}