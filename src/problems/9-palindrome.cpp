#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber / 10;
    }

};


int main(int argc, char *argvp[]) {
    Solution s;

    int nums[] = {123, 121, 123450, -121};

    for (unsigned int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        if (s.isPalindrome(nums[i])) {
            cout << nums[i] << " is palindrome" << endl;
        } else {
            cout << nums[i] << "is not palindrome" << endl;
        }
    }

    return 0;
}