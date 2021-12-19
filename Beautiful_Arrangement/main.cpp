#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    /*
     * Given two integers n and k, construct a list answer that contains n
     * different positive integers ranging from 1 to n and obeys the following requirement:
     * Suppose this list is answer = [a1, a2, a3, ... , an],
     * then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
     * Return the list answer. If there multiple valid answers, return any of them.
     */

    /*
     * Input: n = 3, k = 1
     * Output: [1,2,3]
     * Explanation: The [1,2,3] has three different positive integers ranging from 1 to 3,
     * and the [1,1] has exactly 1 distinct integer: 1
     */

    vector<int> constructArray(int n, int k) {
        vector<int> result;
        deque<int> arr;
        int differents = k;

        for (int i = 1; i <= n; ++i) {
            arr.push_back(i);
        }

        while (true) {
            if (differents == k || n == differents + 1) {
                result.push_back(arr.front());
                arr.pop_front();
            }

            if (differents == 1) {
                for (auto it = arr.begin(); it != arr.end(); it++) {
                    result.push_back(*it);
                }
                return result;
            }
            if (differents == 2) {
                for (auto it = arr.rbegin(); it != arr.rend(); it++) {
                    result.push_back(*it);
                }
                return result;
            }
            result.push_back(arr.back());
            result.push_back(arr.front());
            arr.pop_back();
            arr.pop_front();
            differents -= 2;
        }
    }
};

int main() {
    Solution t;
    {
        int n = 3, k = 1;
        vector<int> expected_vector{1,2,3};
        vector<int> res = t.constructArray(n, k);
        if (res == expected_vector) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }

    {
        int n = 3, k = 2;
        vector<int> expected_vector{1,3,2};
        vector<int> res = t.constructArray(n, k);
        if (res == expected_vector) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }

    {
        int n = 5, k = 4;
        vector<int> expected_vector{1,5,2,4,3};
        vector<int> res = t.constructArray(n, k);
        if (res == expected_vector) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }
        return 0;
}
