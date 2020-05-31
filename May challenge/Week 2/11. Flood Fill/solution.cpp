class Solution {
public:
    bool vis[50][50];
    int maxR;
    int maxC;
    int startColor;
    
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    
    bool isValid(int i, int j,int maxR,int maxC) {
        return i >= 0 && i < maxR && j >=0 && j < maxC;
    }
    
    void floodFill(int sr,int sc,int newColor,vector<vector<int>>& image) {
        if(!isValid(sr,sc,maxR,maxC) || vis[sr][sc] || image[sr][sc] != startColor)
            return;
        
        image[sr][sc] = newColor;
        vis[sr][sc] = true;
        for(int k = 0;k<4;k++){
         floodFill(sr+dr[k],sc+dc[k],newColor,image);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        startColor = image[sr][sc];
        maxR = image.size();
        maxC = image[0].size();
        
        floodFill(sr,sc,newColor,image);
        return image;
    }
};
