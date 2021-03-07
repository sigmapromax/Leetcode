//@Solution 1
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        else if (x >= 0 && x <= 9)
            return true;
        else if (x % 10 == 0)
            return false;
        else {
            int i = 0;
            while (i <= x) {
                i = i * 10 + x % 10;
                x = (x - x % 10) / 10;
                if (i == x || (i * 10 + x % 10) == x)
                    return true;
            }
            return false;
        }
    }
};


//@Solution 1 plus
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int i = 0;
        while (i < x) {
            i = i * 10 + x % 10;
            x /= 10;
        }
        return i / 10 == x || i == x;
    }
};
