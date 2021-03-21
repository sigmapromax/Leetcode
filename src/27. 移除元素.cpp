class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int right = nums.size();
        for (int i = 0; i < nums.size() && res < right; ++i) {
            if (nums[i] == val) {
                while (nums[--right] == val && right > res);
                if (right <= res)
                    break;
                nums[i] = nums[right];
                res++;
                continue;
            } else {
                res++;
            }
        }
        return res;
    }
};