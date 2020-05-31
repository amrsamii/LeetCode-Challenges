/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        int n=preorder.size();
        
        s.push(root);
        
        for(int i=1;i<n;i++){
            TreeNode *temp = NULL;
	    // find the parent which the current node should be right child of
            while(!s.empty() && s.top()->val < preorder[i]){
                temp = s.top();
                s.pop();
            }
            if(temp){
                temp->right = new TreeNode(preorder[i]);
                s.push(temp->right);
            }
            else{
                temp = s.top();
                temp->left = new TreeNode(preorder[i]);
                s.push(temp->left);
            }
        }
        return root;
    }
};
