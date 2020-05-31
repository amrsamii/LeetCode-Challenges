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
    
    int kth;
    int idx = 0;

    void inOrder(TreeNode *root,int k) {
        
        if(root->left != nullptr)
            inOrder(root->left,k);

        idx++;
        if(k == idx) {
            kth = root->val;
            return;
        }
        
        if(root->right != nullptr)
            inOrder(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        inOrder(root,k);
        return kth;
    }
};
