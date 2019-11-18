#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) {
                    r--;
                } else if (s < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    //skip duplicate triplets.
                    while (l < r && nums[l] == nums[++l]);
                    while (l < r && nums[r] == nums[--r]);
                }
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> n = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(n);
    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        cout << "{";
        for (vector<int>::iterator itTmp = (*it).begin(); itTmp != (*it).end(); itTmp++) {
            cout << *itTmp << ",";
        }
        cout << "}";
    }
    return 0;
}