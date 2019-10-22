#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 求最长回文
 * such as: babad,    aba
 *
 * P(i,j) = (P(i+1, j-1) && s[i] == S[j])
 * */

//solution1, 暴力解法太耗时， Time Limit Exceeded

//class Solution {
//public:
//    bool isPalindrome(string s)
//    {
//        int len = s.length();
//        for(int i = 0; i < len / 2; i++) {
//            if (s[i] != s[len - i - 1]) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    string longestPalindrome(string s) {
//        string ans = "";
//        int max = 0;
//        int len = s.length();
//        for(int i = 0; i < len; i++) {
//            for(int j = i+1; j <= len; j++){
//                string test = s.substr(i,j-i);
//                if(isPalindrome(test) && test.length() > max){
//                    ans = test;
//                    max = ans.length();
//                }
//            }
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int len = s.length();
//
//        //p[i,j]表示s[i,j]是否是回文
////        bool p[len][len];
//        vector<vector<bool>> p(len, vector<bool>(len));
//
//        int maxLen = 0;
//        string maxPal = "";
//
//        for(int l = 1; l <= len; l++){
//            for(int start = 0; start <len; start++){
//                int end = start + l -1;
//                if(end >= len) break;
//
//                p[start][end] = (l == 1 || l == 2 || p[start+1][end-1]) &&
//                                s[start] == s[end];
////                cout<<"p["<<start<<"]["<<end<<"]"<<"="<<p[start][end]<<endl;
//                if(p[start][end] && l > maxLen) {
//                    maxPal = s.substr(start, end + 1 - start);
//                }
//            }
//        }
//        return maxPal;
//    }
//};

//采用动态规划的思想，如果p[i][j]为true，那么p[i+1][j-1]也为true。
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        //p[i,j]表示s[i,j]是否是回文
        vector<vector<bool>> p(n, vector<bool>(n));

        int maxLen = 0;
        string maxPal = "";

        for(int i = n -1; i >= 0; i--){
            for(int j = i; j < n; j++) {
                p[i][j] = s[i] == s[j] && (j - i < 2 || p[i+1][j-1]);
//                cout<<"p["<<i<<"]["<<j<<"]"<<"="<<p[i][j]<<endl;
                if(p[i][j] && (j-i+1) > maxPal.length()) {
                    maxPal = s.substr(i, j+1 - i);
                }
            }
        }
        return maxPal;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout<<sol.longestPalindrome("babad")<<endl;
    cout<<sol.longestPalindrome("cbbd")<<endl;
    cout<<sol.longestPalindrome("abcdbbfcba")<<endl;
}