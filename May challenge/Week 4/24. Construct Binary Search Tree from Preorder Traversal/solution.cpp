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

int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
The trick is to set a range {min .. max} for every node. Initialize the range as {INT_MIN .. INT_MAX}. The first node will definitely be in range, so create root node. To construct the left subtree, set the range as {INT_MIN …root->data}. If a values is in the range {INT_MIN .. root->data}, the values is part part of left subtree. To construct the right subtree, set the range as {root->data..max .. INT_MAX}.
*/
// O(n) solution

class Solution {
public:
    int idx = 0;
    int sz;
    
    TreeNode* constructBST(vector<int>& preorder, int min, int max) {
        if (idx == sz)
            return nullptr;
        
        TreeNode *current = nullptr;
        
        if (preorder[idx] > min && preorder[idx] < max) {
            current = new TreeNode{preorder[idx++]};
            
            current->left = constructBST(preorder, min, current->val);
            
            current->right = constructBST(preorder,current->val,max);
        }
        
        return current;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sz = preorder.size();
        
        return constructBST(preorder, INT_MIN, INT_MAX);
    }
};
