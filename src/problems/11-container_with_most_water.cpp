#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxarea = 0;
        int l = 0;
        int r = height.size() - 1;
        int area;
        while (l < r) {
            area = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
            if (area > maxarea) maxarea = area;
            if (height[l] < height[r]) l++;
            else r--;
        }
        return maxarea;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height);
    return 0;
}