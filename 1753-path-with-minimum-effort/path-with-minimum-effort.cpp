class Solution {
public:
typedef pair<int,pair<int,int>>p;
vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        auto safe= [&](int i,int j){
            if(i>=0&&i<m&&j>=0&&j<n) return true;
            else return false;
        };
       
       priority_queue<p,vector<p>,greater<p>>pq;
       pq.push({0,{0,0}});
       res[0][0]=0;
       while(!pq.empty()){
        int diff=pq.top().first;
        pair<int,int> cord=pq.top().second;
        int x=cord.first;
        int y=cord.second;
        pq.pop();
               

          for(auto d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(safe(nx,ny)){
                int absdiff=abs(grid[x][y]-grid[nx][ny]);
                int maxdiff=max(diff,absdiff);
                if(res[nx][ny]>maxdiff){
                    res[nx][ny]=maxdiff;
                    pq.push({maxdiff,{nx,ny}});
                }
            }
          }
       }
       return res[m-1][n-1];
    }
};