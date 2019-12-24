#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    f(i,j)=f(i−1,j−1)+f(i−1,j)
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> data(numRows);

        if (numRows == 0) return data;

        data[0].push_back(1);
        for (int row = 1; row < numRows; ++row) {
            data[row].push_back(1);
            for (int col = 1; col < row; ++col) {
                data[row].push_back(data[row - 1][col] + data[row - 1][col - 1]);
            }
            data[row].push_back(1);
        }
        return data;
    }
};

void PrintArray(vector<vector<int>> &data) {
    for (int i = 0; i < data.size(); i++) {
        for (int sp = 0; sp < data.size() - i; ++sp) {
            cout << " ";
        }

        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> data = s.generate(5);
    PrintArray(data);
}