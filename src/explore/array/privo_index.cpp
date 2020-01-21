#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        if (nums.size() < 2)return -1;
        int left_sum = 0;
        int right_sum = 0;
        int sum = 0;

        for (auto &n : nums) {
            sum += n;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left_sum = 0;
            } else {
                left_sum += nums[i - 1];
            }
            right_sum = sum - left_sum - nums[i];
            if (left_sum == right_sum) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {-1, -1, -1, -1, -1, 0};

    cout << "nums1 pivot:" << s.pivotIndex(nums1) << endl;
    cout << "nums2 pivot:" << s.pivotIndex(nums2) << endl;
    cout << "nums3 pivot:" << s.pivotIndex(nums3) << endl;

    return 0;
}
