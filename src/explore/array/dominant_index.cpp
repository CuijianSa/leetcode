#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        int pre_index = -1;
        int dominant_index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[dominant_index]) {
                pre_index = dominant_index;
                dominant_index = i;
            }
        }

        if (pre_index == -1 || (nums[dominant_index] >= 2 * nums[pre_index])) {
            return dominant_index;
        } else {
            return -1;
        }

    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1 = {3, 6, 1, 0};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1,0};
    cout << s.dominantIndex(nums1) << endl;
    cout << s.dominantIndex(nums2) << endl;
    cout << s.dominantIndex(nums3) << endl;

    return 0;
}