#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    cout << s.addBinary("1010", "1011");
    return 0;
}