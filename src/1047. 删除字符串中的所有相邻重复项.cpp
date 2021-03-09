class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == res.back())
                res.pop_back();
            else
                res += S[i];
        }
        return res;
    }
};