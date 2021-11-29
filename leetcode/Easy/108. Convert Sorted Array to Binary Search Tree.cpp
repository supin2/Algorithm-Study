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
    TreeNode* mySol(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return nullptr;
        }
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = mySol(nums, start, mid);
        root->right = mySol(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return mySol(nums, 0, nums.size());
    }
};

// 16ms solution
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if (nums.size() == 0) {
//             return nullptr;
//         }
//         if (nums.size() == 1) {
//             return new TreeNode(nums.front());
//         }
        
//         int mid = nums.size()/2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         vector<int> lv(nums.begin(), nums.begin() + mid);
//         vector<int> rv(nums.begin() + mid + 1, nums.end());
        
//         root->left = sortedArrayToBST(lv);
//         root->right = sortedArrayToBST(rv);
        
//         return root;
//     }
// };