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

/**
This implementation just converts the in order recurion of solution.cpp into iterative implementation, this way, we can return from the traverse if we find the required number, the complexity then will be O(H+k). in recursion approach, we cannot stop it and we are obliged to make all the in order traverse ans so the complexity was O(N)
*/
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        stack<TreeNode*> tree;
        
        while(true) {
            while(root != nullptr) {
                tree.push(root);
                root = root->left;
            }
            
            root = tree.top(); 
            tree.pop();
            
            if(--k == 0) return root->val;
            
            root = root->right;
        }
    }
};
