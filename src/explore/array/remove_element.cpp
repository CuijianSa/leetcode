#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        vector<int>::iterator it = nums.begin();
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

    vector<int> nums = {3, 2, 2, 3};

    cout << s.removeElement(nums, 3) << endl;

    return 0;
}