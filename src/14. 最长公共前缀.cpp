class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1)
            return "";
        else if (strs.size() == 1)
            return strs[0];
        string res = "";
        int min_size = strs[0].size();
        for (auto i : strs) //找到最短字符串的长度，避免越界
            min_size = min<int>(i.size(), min_size);  

        bool is_same = true;
        int j = 0;  //字符下标
        while (is_same && j < min_size) {
            char temp = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) { //字符串下标
                if (strs[i][j] != temp) {
                    is_same = false;
                    break;
                }
            }
            if (is_same)
                res += strs[0][j];
            j++;
        }
        return res;
    }
};