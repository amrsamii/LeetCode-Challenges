class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(coordinates.size() == 2)
            return true;
        
        double num = coordinates[0][1] - coordinates[1][1];
        double den = coordinates[0][0] - coordinates[1][0];
        
        double m = num/den;
        double c = coordinates[0][1] - (m * coordinates[0][0]);
        
        for(int i = 2; i < coordinates.size(); i++) {
            
         if (coordinates[i][1] != (m*coordinates[i][0] + c))
             return false;
        }
        return true;
    }
};
