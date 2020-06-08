class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> res;
        
        sort(people.begin(),people.end(),[](const vector<int>& a, const vector<int>& b) {
	    // sort based on height in decreasing order, if same height, sort based on k value in increasing order
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        for (int i = 0; i < people.size(); i++) {
            auto it = res.begin();
	    // move iterator to insert in k-th position
            advance(it, people[i][1]);
            
            res.insert(it,people[i]);
        }
       
        
        return vector<vector<int>>(res.begin(),res.end());
    }
};
