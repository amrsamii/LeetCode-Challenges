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
        int dx = 0, dy = 0;
        TreeNode* px, *py;
    
        void traverse(TreeNode *root,int x, int y,TreeNode* parent = nullptr, int depth = 0) {
            if (root == nullptr) {
                return;

            }


            if(root->val == x){
                dx = depth;
                px = parent;
            }
            
            if(root->val == y){
            dy = depth;
            py = parent;
            }
            traverse(root->left,x,y,root,depth+1);
            traverse(root->right,x,y,root,depth+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        
        traverse(root,x,y);
        
        cout << dx << endl << dy << endl;
        
        return  dx == dy && px != py;
        
    }
};
