#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    Solution() {
        romanMap = {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"}
        };
    }

    string intToRoman(int num) {
        string s = "";
        auto itr = romanMap.end() - 1;
        while (num && itr != romanMap.begin() - 1) {
            if (num >= itr->first) {
                num -= itr->first;
                s += itr->second;
            } else {
                itr--;
            }
        }
        return s;
    }

private:
    vector<pair<int, string>> romanMap;
};


int main(int argc, char *argv[]) {
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;

    return 0;
}