class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        int cntfresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=0;
                }
                else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1) cntfresh++;
            }
        }

        int tm=0;
        int cnt1=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();

            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                tm=max(tm,t);
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt1++;
                }
            }
        }

        if(cntfresh!=cnt1) return -1;
        return tm;
    }
};