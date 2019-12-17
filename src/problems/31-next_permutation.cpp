#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;

        //find first element, nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            //find element that right > left
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
};

void PrintNums(vector<int> nums) {
    for (auto num = nums.begin(); num != nums.end(); num++) {
        cout << *num << ",";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    PrintNums(nums);

    nums = {3, 2, 1};
    s.nextPermutation(nums);
    PrintNums(nums);

    nums = {1, 1, 5};
    s.nextPermutation(nums);
    PrintNums(nums);

    return 0;
}