#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    /**
     * INT32 [-2147483648,2147483647]
     *
     * temp = rev * 10 + pop
     *
     * 1. temp溢出,rev >= INTMAX / 10
     * 2. rev > UINTMAX / 10, overflow
     * 3. rev = UINTMAX / 10, pop > 7, temp 溢出
     *
     * */

    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.reverse(123)<<endl;
    cout<<s.reverse(-123)<<endl;
    cout<<s.reverse(120)<<endl;
}