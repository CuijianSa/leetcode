#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
//    string longestCommonPrefix(string s1, string s2) {
//        string commonPrefix = "";
//        bool isMatch = false;
//        unsigned int first = 0, second = 0;
//        for (unsigned int i = 0; i < s1.length(); i++) {
//            isMatch = false;
//            first = second = i;
//            while (first < s1.length() && second < s1.length() && !isMatch) {
//                for (unsigned int j = 0; j < s2.length(); j++) {
//                    if (s1[second] == s2[j]) {
//                        if (!isMatch) {
//                            isMatch = true;
//                            first = second;
//                        }
//                    } else {
//                        if (isMatch) {
//                            break;
//                        } else {
//                            first++;
//                        }
//                    }
//                    second++;
//                }
//            }
//            if ((second - first) > commonPrefix.size()) {
//                commonPrefix = s1.substr(first, second - first);
//            }
//        }
//        return commonPrefix;
//    }
//
//    string longestCommonPrefix(vector<string> &strs) {
//
//        vector<string>::iterator it;
//        if (strs.size() == 0) return "";
//        if (strs.size() < 1) return strs[0];
//        it = strs.begin();
//        string commPrefix = *it++;
//        for (; it != strs.end(); it++) {
//            commPrefix = longestCommonPrefix(commPrefix, *it);
//        }
//        return commPrefix;
//    }

    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        vector<string>::iterator it = strs.begin();
        string prefix = strs[0];
        int preLen = strs[0].length();

        for (; it != strs.end(); it++) {
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