#include <iostream>
#include <vector>

using namespace std;

//vector<vector<int>> data(numRows);
//
//if (numRows == 0) return data;
//
//data[0].push_back(1);
//for (int row = 1; row < numRows; ++row) {
//data[row].push_back(1);
//for (int col = 1; col < row; ++col) {
//data[row].push_back(data[row - 1][col] + data[row - 1][col - 1]);
//}
//data[row].push_back(1);
//}
//return data;

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

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> data = generate(rowIndex+1);
        return data[rowIndex];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> row = s.getRow(3);
    for (auto v:row) {
        cout << v << " ";
    }
    return 0;
}