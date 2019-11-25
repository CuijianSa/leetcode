#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {
        m = unordered_map<char, string>{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
    }

    void backtrack(string combination, string nextDigits) {
        if (nextDigits.size() == 0) {
            output.push_back(combination);
            return;
        } else {
            string letters = m[nextDigits[0]];
            for (auto letter: letters) {
                backtrack(combination + letter, nextDigits.substr(1, nextDigits.size() - 1));
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0) {
            backtrack("", digits);
        }
        return output;
    }

private:
    unordered_map<char, string> m;
    vector<string> output;
};


int main(int argc, char *argv[]) {
    Solution s;
//    vector<string> output = s.letterCombinations("234");
    vector<string> output = s.letterCombinations("");
    for (auto s:output) {
        cout << s << endl;
    }

    return 0;
}
