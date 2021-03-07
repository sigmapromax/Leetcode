class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int num_0 = 0, num_2 = nums.size();
        int i = 0;
        while (i < num_2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[num_0]);
                num_0++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                num_2--;
                swap(nums[i], nums[num_2]);
            }
        }
    }
};
