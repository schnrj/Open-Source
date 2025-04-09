class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int x) {
        // int n=edges.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int c=it[2];
            dist[u][v]=c;
            dist[v][u]=c;
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cnt=n;
        int city=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
              if(dist[i][j]<=x) count++;
            }
            if(cnt>=count){
                cnt=count;
                city=i;
            }
        }
        return city;
    }
};