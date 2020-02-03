#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max_consecutive_ones = 0;

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                if (max_consecutive_ones < count) {
                    max_consecutive_ones = count;
                }
                count = 0;
            }
        }

        if (max_consecutive_ones < count) {
            max_consecutive_ones = count;
        }

        return max_consecutive_ones;
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << s.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}