// Time complexity: O(n)
// Space complexity: O(1) sort in place
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // need predicate to find first n closest points to origin, so we need to tell it how to know if point is close to origin by predicate
        nth_element(points.begin(),points.begin()+K-1,points.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        points.resize(K);
        
        return points;
    }
};
