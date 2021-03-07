class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); ++i) {
            auto j = s.find(target - nums[i]);
                if (j != s.end())
                    return {j->second, i};
            s[nums[i]] = i;
        }
        return {};
    }
};
