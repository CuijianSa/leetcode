#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = target;
        int N = nums.size();
        sort(nums.begin(), nums.end());

        int l, r;
        int sum;
        int minDf = INT32_MAX;
        for (int i = 0; i < N - 2; i++) {
            l = i + 1;
            r = N - 1;

            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                if (abs(sum - target) < minDf) {
                    res = sum;
                    minDf = abs(res - target);
                }
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }

        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {-1, 2, 1, -4};

    cout << s.threeSumClosest(nums, 1);

    return 0;

}