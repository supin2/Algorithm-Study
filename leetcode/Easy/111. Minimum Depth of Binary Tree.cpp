#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr) {
            return 1 + dfs(node->right);
        }
        if (node->right == nullptr) {
            return 1 + dfs(node->left);
        }
        return 1 + min(dfs(node->left), dfs(node->right));
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};