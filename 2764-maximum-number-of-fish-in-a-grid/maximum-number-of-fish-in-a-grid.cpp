class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int m,int n){
        if(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]>0){
            int x=grid[i][j];
            grid[i][j]=0;
            return x+dfs(grid,i+1,j,m,n)+dfs(grid,i-1,j,m,n)+dfs(grid,i,j-1,m,n)+dfs(grid,i,j+1,m,n);
        }
        return 0;
    }
    int findMaxFish(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                   int  count=dfs(grid,i,j,m,n);
                   ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};