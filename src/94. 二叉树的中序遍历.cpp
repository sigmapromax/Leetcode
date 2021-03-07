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
//@Solution 1
// O(n) 
// O(n)
class Solution {
public:
    void func(TreeNode* p, vector<int>& res_) {
        if (p == nullptr)
            return;
        func(p->left, res_);
        res_.push_back(p->val);
        func(p->right, res_);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        func(root, res);
        return res;
    }
};

//@Solution 2 Morris中序遍历算法 
// O(n)
// O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* pre = nullptr;
        while (root != nullptr) {
            if (root->left != nullptr) {
                pre = root->left;
                while (pre->right != nullptr && pre->right != root)
                    pre = pre->right;
                if (pre->right == nullptr) {
                    pre->right = root;
                    root = root->left;
                }
                else {
                    res.push_back(root->val);
                    pre->right = nullptr;   //断开连接，保留原结构
                    root = root->right;
                }
            }
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }     
        return res;
    }
};