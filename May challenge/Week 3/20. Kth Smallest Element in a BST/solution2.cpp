class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root = root->left;
            }
            auto top = st.top();
            if(!(--k)){return top->val;}
            st.pop();
            root = top->right;
        }
        return -1;
    }
};
