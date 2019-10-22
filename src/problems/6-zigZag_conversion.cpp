#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 根据输入指定的行数，从上到下，从左到右Z排列
     * 从左到右迭代 sss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
     * */
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for(char c:s) {
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows -1) goingDown = !goingDown;
            curRow += goingDown ? 1:-1;
        }
        string ret;
        for(string row: rows) ret += row;
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.convert("LEETCODEISHIRING", 3)<<endl;
    return 0;
}