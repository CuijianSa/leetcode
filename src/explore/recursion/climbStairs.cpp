#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    //每次最多攀爬2层， 符合fibonacci数列, f(b) = f(b-1) + f(b-2) 且f(1) = 1, f(2) = 2
    int climbStairs(int n) {
        if (fibMap.find(n) != fibMap.end()) return fibMap[n];
        int result = 0;
        if (n <= 2) {
            result = n;
        } else {
            result = climbStairs(n - 1) + climbStairs(n - 2);
        }

        fibMap[n] = result;
        return result;
    }

private:
    map<int, int> fibMap;
};


int main(int argc, char *argv[]) {
    Solution s;

    cout<<"climbStairs(2): "<<s.climbStairs(2)<<endl;
    cout<<"climbStairs(3): "<<s.climbStairs(3)<<endl;
    return 0;
}