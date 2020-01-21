#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (n < 0) {
            //计算阶乘因子
            x = 1 / x;
            N = -N;
        }
//        over timelimit
//        double ans = 1;
//        for (long long i = 0; i < N; i++) {
//            ans = ans * x;
//        }
//        return ans;

        double  ans = 1;
        double current_product = x;
        for(long long i = N; i; i /= 2) {
            if(i%2) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution s;

    cout << "2^10=" << s.myPow(2, 10) << endl;
    cout << "2.1^3=" << s.myPow(2.1, 3) << endl;
    cout << "2^-2=" << s.myPow(2, -2) << endl;

    return 0;
}