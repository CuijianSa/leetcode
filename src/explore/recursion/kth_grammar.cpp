#include <iostream>

using namespace std;

class Solution {
public:
    //S(n) = F((n+1)/2), S(n) = F((n+1)/2)) == 0 ? 1-(K%2) : (K%2)
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return kthGrammar(N - 1, (K + 1) / 2) == 0 ? 1 - (K % 2) : (K % 2);
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    cout << "kthGramar(1,1):" << s.kthGrammar(1, 1) << endl;
    cout << "kthGramar(2,1):" << s.kthGrammar(2, 1) << endl;
    cout << "kthGramar(2,2):" << s.kthGrammar(2, 2) << endl;
    cout << "kthGramar(4,5):" << s.kthGrammar(4, 5) << endl;

    return 0;

}