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
    vector<int> ret;
public:
    void traverse(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        ret.push_back(node->val);
        inorderTraversal(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return ret;
    }
};