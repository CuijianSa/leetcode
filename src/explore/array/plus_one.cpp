#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> sums = {01, 2, 3};
    vector<int> res = s.plusOne(sums);
    for (auto &e:res) {
        cout << e;
    }
    return 0;
}