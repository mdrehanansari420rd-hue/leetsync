class Solution {
private:
    void bfs(int startNode,vector<vector<int>> &isConnected,vector<int> &vis){
        vis[startNode]=1;
        int n=isConnected.size();
        queue<int>q;
        q.push(startNode);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int neighbour=0;neighbour<n;neighbour++){
                if( !vis[neighbour] && isConnected[node][neighbour]==1){
                    vis[neighbour]=1;
                    q.push(neighbour);
                    }
                }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;

        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
                if(!vis[i]){
                    count++;
                    vis[i]=1;
                    bfs(i,isConnected,vis);
                }
        }
        return count;
    }
};