#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     *
     * 二分法查找, 从i-j查找，直到sums[j]-sums[i] + nums[i] > s
     *
     *          sums[i]     sums[j]
     * |///////////| nums[i] | //////////////
     *
     *
     * 其实还可以用双指针，first指向数组起始地址， last指向最后的位置。
     * 求其两个指针指向的和差求最小值
     */

    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = INT_MAX;

        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;

}