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
    bool mySolution(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r != nullptr) {
            return false;
        }
        if (l != nullptr && r == nullptr) {
            return false;
        }
        if (l == nullptr && r == nullptr) {
            return true;
        }
        if (l->val != r->val) {
            return false;
        }
        return mySolution(l->right, r->left) && mySolution(l->left, r->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return mySolution(root->left, root->right);
    }
};