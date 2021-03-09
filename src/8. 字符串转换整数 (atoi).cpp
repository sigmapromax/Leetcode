class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, res = 0, i = 0;
        while(s[i] == ' ')  
            ++i;    
        if(s[i] == '+' || s[i] == '-')
            sign = 1 - 2 * (s[i++] == '-');
        while(s[i] >= '0' && s[i] <= '9')
        {
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (s[i++] - '0');
        }
        return res * sign;
    }
};