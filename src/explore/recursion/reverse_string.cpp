#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            int tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};

    s.reverseString(str);

    for (const auto &c:str) {
        cout << c << " ";
    }
    cout << endl;
}