// collinear means all points lie on the same straight line
// to check if two vectors are collinear: v1(x,y) v2(x',y') => x * y' - x' * y = 0 means they are collinear, otherwise, they are not.
// to check collinearity, we can use cross product, or just make a line with first two points and then substitute with every point in the line 	   to check if it lies on the line. line is defined by m and c  

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size() == 2)
            return true;
        
        int x1 = coordinates[0][0];
        int x2 = coordinates[1][0];
        int y1 = coordinates[0][1];
        int y2 = coordinates[1][1];
        
        int u = x2-x1;
        int v = y2-y1;
        
        for(int i = 2; i < coordinates.size() - 1; i++) {
            
            int x1 = coordinates[i][0];
            int x2 = coordinates[i+1][0];
            int y1 = coordinates[i][1];
            int y2 = coordinates[i+1][1];
            
            int u2 = x2-x1;
            int v2 = y2-y1;
            
            int cross = u*v2-u2*v;
            if(cross != 0)
                return false;
        }
        return true;
    }
};


