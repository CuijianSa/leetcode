#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int sum;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = j + 1, l = n - 1;
                while (k < l) {
                    sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});

                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;
                        k++;
                        l--;
                    }
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = s.fourSum(nums, 0);

    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        cout << "{";
        for (vector<int>::iterator itTmp = (*it).begin(); itTmp != (*it).end(); itTmp++) {
            cout << *itTmp << ",";
        }
        cout << "}";
    }


    return 0;
}