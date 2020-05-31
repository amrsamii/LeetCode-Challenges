class Solution {
public:
    int kadane(vector<int>& A) {
        int max_current = A[0];
        int max_global = A[0];
        
        for(int i=1;i<A.size() ;i++) {
            max_current = max(A[i],max_current + A[i]);
            if(max_current > max_global)
                max_global = max_current;
        }
        return max_global;
    }
    
    
    int maxSubarraySumCircular(vector<int>& A) {
        int max_kadane = kadane(A);
        
        int max_wrap = 0;
        
        for(int i=0;i<A.size();i++) {
            max_wrap += A[i];
            A[i] = -A[i];
        }

        // max sum with corner elements will be:  
       // array-sum - (-max subarray sum of inverted array)  
        max_wrap += kadane(A);
        
        return (max_kadane > max_wrap || max_wrap == 0) ? max_kadane : max_wrap;
    }
};
