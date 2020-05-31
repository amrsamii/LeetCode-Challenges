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
    
        TreeNode *iterate(TreeNode *root, int data, int &depth) {
        if (root == nullptr || root->val == data) {
            return nullptr;

        } else if ((root->left != nullptr && root->left->val == data) ||
                   (root->right != nullptr && root->right->val == data)) {
            depth++;
            return root;

        } else {
            int d = depth;
            TreeNode *found = iterate(root->left, data, ++depth);
            if (found == nullptr) {
                depth = d;
                found = iterate(root->right,data,++depth);
            }
            return found;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int dx = 0, dy = 0;
        TreeNode* px, *py;
        
        px = iterate(root,x,dx);
        py = iterate(root,y,dy);
        
        cout << dx << endl << dy << endl;
        
        return  dx == dy && px != py;
        
    }
};
