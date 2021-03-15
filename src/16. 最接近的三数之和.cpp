class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                    return target;
                update(sum);
                if (sum > target) {
                    int right_t = right - 1;
                    while (right_t > left && nums[right_t] == nums[right])
                        right_t--;
                    right = right_t;
                }
                else {
                    int left_t = left + 1;
                    while (right > left_t && nums[left_t] == nums[left])
                        left_t++;
                    left = left_t;
                }
            }            
        }
        return best;
    }
};