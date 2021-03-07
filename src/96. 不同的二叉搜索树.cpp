//Solution 1
//O(n^2)
//O(n)
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                res[i] += res[j - 1] * res[i - j];

        return res[n];
    }
};

//Solution 2 卡塔兰数公式
//O(n)
//O(1)
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};