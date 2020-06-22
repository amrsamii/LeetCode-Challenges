class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int low = 0, high = n;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // we try to find first number >= n - mid because it will be the solution in linear search, so make low and 
            // high points at that number, if you find it, don't leave it, because it maybe the solution
            if (citations[mid] >= n - mid)
                high = mid;
            // this will never be the solution so make low = mid + 1
            else
                low = mid + 1;       
        }
        return n - low;
    }
};
