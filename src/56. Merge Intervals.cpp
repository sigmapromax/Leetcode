class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int min_num = intervals[0][0], max_num = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > max_num) {
                res.push_back({min_num, max_num});
                min_num = intervals[i][0];
                max_num = intervals[i][1];
            }else {
                min_num = min(min_num, intervals[i][0]);
                max_num = max(max_num, intervals[i][1]);
            }
            if (i == intervals.size() - 1) {
                    res.push_back({min_num, max_num});
            }
        }
        return res;
    }
};