#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        size_t res = haystack.find(needle);
        if (res == string::npos) {
            return -1;
        } else {
            return res;
        }
    }
};


int main() {
    Solution t;
    {
        int res = t.strStr("hello", "ll");
        if (res == 2) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }

    {
        int res = t.strStr("aaaaaaaaaaa", "baaaa");
        if (res == -1) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }

    {
        int res = t.strStr("hello", "");
        if (res == 0) {
            cout << "PASSED" << endl;
        } else {
            cout << "FAILED" << endl;
        }
    }
        return 0;
}
