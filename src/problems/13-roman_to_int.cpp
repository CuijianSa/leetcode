#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    Solution() {
        rm = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
    }

    int romanToInt(string s) {
        string first = "";
        string second = "";

        int sum = 0;

        for (unsigned int i = 0; i < s.length(); i++) {
            if (rm[s[i]] < rm[s[i + 1]]) {
                sum += rm[s[i + 1]] - rm[s[i]];
                i++;
            } else {
                sum += rm[s[i]];
            }
        }
        return sum;
    }

private:
    map<char, int> rm;
};

int main(int argc, char *arv[]) {
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;

    return 0;
}