#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        vector<int> res;
//
//        for (int i = 0; i < numbers.size(); i++) {
//            for (int j = numbers.size() - 1; j > i; j--) {
//                if (numbers[i] + numbers[j] == target) {
//                    res.push_back(i + 1);
//                    res.push_back(j + 1);
//                    return res;
//                }
//            }
//        }
//        return res;
//    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> num_map;

        for (int i = 0; i < numbers.size(); i++) {
            num_map[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            auto it = num_map.find(target - numbers[i]);
            if (it != num_map.end() && it->second != i) {
                return vector<int>{i + 1, it->second + 1};
            }
        }
        return vector<int>{};
    }
};


int main(int argc, char *argv[]) {
    Solution s;

    vector<int> numbers = {2, 7, 11, 15};

    vector<int> res = s.twoSum(numbers, 9);

    for (auto &e: res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}