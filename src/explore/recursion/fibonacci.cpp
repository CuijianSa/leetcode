#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
//    f(0) = 0, f(1) = 1, f(n) = f(n-1) + f(n-2)
    int fib(int N) {
        if (fibMap.find(N) != fibMap.end()) return fibMap[N];
        int result = 0;
        if (N < 2) {
            result = N;
        } else {
            result = fib(N - 1) + fib(N - 2);
        }

        fibMap[N] = result;
        return result;
    }

private:
    map<int, int> fibMap;
};


int main(int argc, char *argv[]) {
    Solution s;
    cout << "fib(2)：" << s.fib(2) << endl;
    cout << "fib(3)：" << s.fib(3) << endl;
    cout << "fib(4)：" << s.fib(4) << endl;
    return 0;
}