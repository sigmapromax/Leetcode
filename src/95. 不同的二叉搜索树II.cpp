/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end)
            return {nullptr};
        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            for (auto& left : leftTrees)
                for (auto& right : rightTrees) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = left;
                    curr->right = right;
                    allTrees.emplace_back(curr);
                }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n)
            return {};
        return generateTrees(1, n);
    }
};