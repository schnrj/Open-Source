class Solution {
public:
typedef pair<int,pair<int,int>>p;
vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        auto safe= [&](int i,int j){
            if(i>=0&&i<m&&j>=0&&j<n) return true;
            else return false;
        };
       
       priority_queue<p,vector<p>,greater<p>>pq;
       pq.push({grid[0][0],{0,0}});
       res[0][0]=grid[0][0];
       while(!pq.empty()){
        int diff=pq.top().first;
        pair<int,int> cord=pq.top().second;
        int x=cord.first;
        int y=cord.second;
        pq.pop();
        if (x == m - 1 && y == n - 1) return diff;

               

          for(auto d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(safe(nx,ny)){
                int newt=max(diff,grid[nx][ny]);
                
                if(res[nx][ny]>newt){
                    res[nx][ny]=newt;
                    pq.push({newt,{nx,ny}});
                }
            }
          }
       }
       return res[m-1][n-1];
    }
};