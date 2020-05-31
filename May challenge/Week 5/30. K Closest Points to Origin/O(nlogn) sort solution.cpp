// Time complexity: O(nlogn)
// Space Complexity: O(1) sort in place
int speed = []() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       
        sort(points.begin(),points.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        
	// make size of points vector be k which will return only the closest k points to origin
        points.resize(K);
        return points;
    }
};
