class Solution {
public:
    const int dirx[4]={0,0,1,-1};
    const int diry[4]={1,-1,0,0};
    bool isValid(vector<vector<int>>& image,int r,int c,int n,int m,int currColor){
        if(r>=0 && r<n && c>=0 && c<m && image[r][c]==currColor)return 1;
        return 0;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int currColor){
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=newColor;
        for(int i=0;i<4;i++){
            if(isValid(image,sr+dirx[i],sc+diry[i],n,m,currColor)){
                dfs(image,sr+dirx[i],sc+diry[i],newColor,currColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int currColor=image[sr][sc];
        if(currColor!=newColor)
        dfs(image,sr,sc,newColor,currColor);
        return image;
    }
};