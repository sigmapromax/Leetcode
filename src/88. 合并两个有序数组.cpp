class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 若数组2为空，则直接返回数组1
        if (n == 0)
            return; 
        int count = 0; 
        
        // 遍历数组1，将更大的数放到数组2中
        for (int i = 0; i < m; i++) { 
                if (nums1[i] > nums2[0]) { 
                    swap(nums1[i], nums2[0]); 
                    sort(nums2.begin(), nums2.end());
                } 
            count++;
            }

        // 将数组2放进数组1
        int j = 0; 
        for (int i = count; i < nums1.size(); i++) {
            nums1[i] = nums2[j];
            j++;
        }
    }

    void swap(int &a, int &b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};