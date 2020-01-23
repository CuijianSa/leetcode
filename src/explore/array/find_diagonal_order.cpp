#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

typedef struct {
    unsigned long x;
    unsigned long y;
} RECT;


class Solution {
public:
    //首先右上(1,-1)，到达界限左下(-1,+1)

#if 1
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        //maxtrix是一个矩阵，不需要关注宽高不等的情况
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();

        if (m == 0 || n == 0) return res;

        for (int l = 0; l < m + n - 1; l++) {
            if(l % 2) { //down
                int i = (l < n ? 0 : (l - n + 1));
                int j = (l < n ? l : (n - 1));
                while (i < m && j >= 0) {
                    res.push_back(matrix[i][j]);
                    i++;
                    j--;
                }
            }else {
                int i = (l < m ? l : (m - 1));
                int j = (l < m ? 0 : (l - m + 1));
                while(i >= 0 && j < n){
                    res.push_back(matrix[i][j]);
                    i--;
                    j++;
                }
            }
        }

        return res;
    }
#endif
};


int main(int argc, char *argv[]) {
    int N = 3;
    vector<vector<int>> matrix;
    for (int i = 0; i < N; i++) {
        vector<int> second_v;
        for (int j = 1; j <= N; j++) {
            second_v.push_back(i * N + j);
        }
        matrix.push_back(second_v);
    }

    Solution s;

    vector<int> res = s.findDiagonalOrder(matrix);
    for (auto e:res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;


}

