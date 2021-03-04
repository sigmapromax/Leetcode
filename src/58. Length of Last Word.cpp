class Solution {
public:
    int lengthOfLastWord(string s) {
        if (!s.size())
            return 0;
        int ans = 0;
        bool isfind = false;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != ' ')
                isfind = true;
            else if (isfind == true && s[i] == ' ')
                break;
            if (isfind == true)
                ans++;
        }
        return ans;
    }
};