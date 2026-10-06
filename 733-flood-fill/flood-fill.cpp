class Solution {
private:
    void dfs(int row,int col,int ini,int color,vector<vector<int>>& image,vector<vector<int>>& ans){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==ini){
                dfs(nrow,ncol,ini,color,image,ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,ini,color,image,ans);
        return ans;
    }
};