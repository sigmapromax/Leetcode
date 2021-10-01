class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        int max = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] > nums[i] + dp[i - 1] ? nums[i] : nums[i] + dp[i - 1];
            if (max < dp[i]) max = dp[i];
        }
        
        return max;
    }
};


// 时间复杂度：O(n)
// dp[i] = max(nums[i], nums[i] + dp[i - 1]);