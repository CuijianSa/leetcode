#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        auto it = nums.begin();

        while (it != nums.end()) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {1,1,2,3,4,5};

    cout<<s.removeElement(nums, 2);

    return 0;
}