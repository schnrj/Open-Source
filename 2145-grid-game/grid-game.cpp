class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topsum=0,bottsum=0;
        for(int i=0;i<grid[0].size();i++){
            topsum+=grid[0][i];
        }
        long long minsum=LLONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            topsum-=grid[0][i];
          long long x=  max(topsum,bottsum);
            minsum=min(minsum,x);
            bottsum+=grid[1][i];
        }
        return minsum;
    }
};