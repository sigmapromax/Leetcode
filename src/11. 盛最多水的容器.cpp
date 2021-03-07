class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (r > l) {
            ans = height[l] < height[r] ? 
                max(ans, (r - l) * height[l++]): 
                max(ans, (r - l) * height[r--]); 
        }
        return ans;
    }
};
