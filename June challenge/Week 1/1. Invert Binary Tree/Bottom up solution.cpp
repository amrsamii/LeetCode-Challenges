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

// Time complexity: O(n)
// Space complexity: O(n)
// Bottom up, invert children then invert current node subtrees
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		// Base case, also handles [] test case
		// don't forget to handle [] test case, it's corner case and you should be careful and always think of them
        if (root == nullptr)
            return root;

        // If root is not null, you can call root->left and root->right safely, if they are null, the above condition
		// will stop the recursion and return null. 
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left,root->right);
        
        return root;
    }
};
