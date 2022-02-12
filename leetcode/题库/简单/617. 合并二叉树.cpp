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
    TreeNode* merge(TreeNode* r1, TreeNode* r2){
        if (!r1 && !r2){
            return nullptr;
        }
        int val{0};
        TreeNode* root{};
        if (r1){
            root = r1;
            val += r1->val;
        }
        if (r2){
            if (!root){
                root = r2;
            }
            val += r2->val;
        }
        root->val = val;
        auto left = merge(r1 ? r1->left : nullptr, r2 ? r2->left : nullptr);
        auto right = merge(r1 ? r1->right : nullptr, r2 ? r2->right : nullptr);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};