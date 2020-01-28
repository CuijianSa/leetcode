#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int height = matrix.size(), width = matrix[0].size();
        vector<int> res;
        int up = 0, down = height - 1, left = 0, right = width - 1;
        for (;;) {
            //  left----> right
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[up][j]);
            };
            if (++up > down) break;
            //  up
            //  |
            //  V
            //  down
            for (int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }

            // left <------right
            for (int j = right; j >= left; j--) {
                res.push_back(matrix[down][j]);
            }
            if (--down < up) break;
            //  up
            //  ^
            //  |
            //  down
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    Solution s;
    vector<int> spiral = s.spiralOrder(matrix);
    for (auto &e: spiral) {
        cout << e << " ";
    }
    cout << endl;
}