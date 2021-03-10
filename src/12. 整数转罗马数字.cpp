class Solution {
public:
    string intToRoman(int num) {
        string str = "";
        int v[7] = {1, 5, 10, 50, 100, 500, 1000};
        char c[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int i = 6;
        while (num > 0 && i >= 0) {
            int temp = num / v[i];
            int store = temp;
            if (temp == 0) {
                i -= 2;
                continue;
            }
            if (temp == 4) 
                str = str + c[i] + c[i + 1];
            else if (temp == 5)
                str += c[i + 1];
            else if (temp == 9)
                str = str + c[i] + c[i + 2];
            else {
                if (temp > 5) {
                    str += c[i + 1];
                    temp -= 5;
                }
                for (int j = 0; j < temp; ++j) {
                    str += c[i];
                }
            }            
            num = num - store * v[i];
            i -= 2;
        }
        return str;
    }
};