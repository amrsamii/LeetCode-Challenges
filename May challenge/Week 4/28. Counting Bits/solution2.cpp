class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        // if num = 0, ans will be of size 1 and initial value is 0, so no need to start from 0, start from 1
        for (int i = 1; i <= num; i++) {
            ans[i] = 1 + ans[i & i-1];
        }
        return ans;
    }
};
