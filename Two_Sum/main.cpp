#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> caches;

        for (size_t i = 0; i < nums.size(); ++i) {
            int cache = target - nums[i];
            try {
                int index = caches.at(cache);
                return vector<int>{index, (int)i};
            }
            catch (const out_of_range& e) {
                caches.insert(pair<int, int>(nums[i], i));
                continue;
            }
        }
        return result;
    }
};

int main() {
    Solution t;

    {
        vector<int> nums{2,7,11,15};
        int target = 9;
        vector<int> res = t.twoSum(nums, target);
        cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    }

    {
        vector<int> nums{7,2,11,15};
        int target = 9;
        vector<int> res = t.twoSum(nums, target);
        cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    }

    {
        vector<int> nums{3,2,4};
        int target = 6;
        vector<int> res = t.twoSum(nums, target);
        cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    }

    {
        vector<int> nums{3,3};
        int target = 6;
        vector<int> res = t.twoSum(nums, target);
        cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    }

    return 0;
}
