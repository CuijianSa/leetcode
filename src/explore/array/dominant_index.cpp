#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        int biggest = INT32_MIN;
        int secondBig = INT32_MIN;
        int point = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > biggest) {
                point = i;
                secondBig = biggest;
                biggest = nums[i];
            } else if (nums[i] > secondBig) {
                secondBig = nums[i];
            }
        }
        return secondBig * 2 > biggest ? -1 : point;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums1 = {3, 6, 1, 0};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1, 0};
    vector<int> nums4 = {0, 0, 3, 2};
    cout << s.dominantIndex(nums1) << endl;
    cout << s.dominantIndex(nums2) << endl;
    cout << s.dominantIndex(nums3) << endl;
    cout << s.dominantIndex(nums4) << endl;

    return 0;
}