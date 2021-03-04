class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int min_num = newInterval[0], max_num = newInterval[1];
        vector<vector<int>> res;
        bool isfind = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > max_num) {
                if (!isfind) {
                    res.push_back({min_num, max_num});
                    isfind = 1;
                }
                res.push_back({intervals[i][0], intervals[i][1]});
            } else if (intervals[i][1] < min_num) {
                res.push_back({intervals[i][0], intervals[i][1]});
            } else {
                min_num = min(min_num, intervals[i][0]);
                max_num = max(max_num, intervals[i][1]);
            }
        }
        if (!isfind)
            res.push_back({min_num, max_num});
        return res;
    }
};