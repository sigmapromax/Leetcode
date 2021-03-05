class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> list;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                list.push_back(nums1[i]);
                list.push_back(nums2[j]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                list.push_back(nums2[j]);
                j++;
            } else if (nums1[i] < nums2[j]) {
                list.push_back(nums1[i]);
                i++;
            }
        }
        if (i >= nums1.size()) {
            for (int n = j; n < nums2.size(); ++n)
                list.push_back(nums2[n]);
        } else if (j >= nums2.size()) {
            for (int n = i; n < nums1.size(); ++n)
                list.push_back(nums1[n]);
        }
        if ((nums1.size() + nums2.size()) % 2 != 0)
            return list[(nums1.size() + nums2.size()) / 2];
        else
            return ((double)(list[(nums1.size() + nums2.size()) / 2] + list[((nums1.size() + nums2.size()) / 2) - 1])) / 2;
    }
};