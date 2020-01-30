#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        if (s.size() == 0) return;
        char tmp;
        char *first = &s[0];
        char *last = &s[s.size() - 1];

        while (first < last) {
            tmp = *last;
            *last = *first;
            *first = tmp;
            first++;
            last--;
        }
        return;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
//    vector<char> str = {'h','e','l','l','o'};
    vector<char> str = {'H', 'a', 'n', 'n', 'a', 'h'};
    s.reverseString(str);

    for (auto &e : str) {
        cout << e << " ";
    }

    cout << endl;
    return 0;
}