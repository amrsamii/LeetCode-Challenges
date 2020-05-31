/**
This is lambda expression, used it since I only need this code once, so function is not required.
Top level because I need to call it in the place of declaration.
To to actually call it after definition ( () after } ), you need to make it return something and store it in a variable.
If you didn't make it return something, compiler error will arise complaining that speed variable cannot be of type void, return 0 is enough.
*/
int speed = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        
	// exit the loop if you reached the end of any list, since there will no be intersected intervals anymore
        while (i < A.size() && j < B.size()) {
            int c1 = max(A[i][0],B[j][0]);
            int c2 = min(A[i][1],B[j][1]);
            
	    // If c1 = 5, c2 = 3, it isn't interval
            if(c1 <= c2)
                ans.push_back({c1,c2});
            
	    // Remove the interval with the smallest endpoint, since it is smaller than the current one, it cannot be intersected with next one
	    // because intervals of the list are pairwise disjoint, this means that they are not intersected with each other
	    // Ex [2,3] [4,5] correct i/p but [2,3] [3,4] or [2,4] [3,5] are incorrect i/p
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
                
        }
        
        return ans;
    }
};
