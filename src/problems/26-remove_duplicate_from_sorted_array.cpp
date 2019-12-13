#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2, 5, 6};

    cout << s.removeDuplicates(nums);

    return 0;

}