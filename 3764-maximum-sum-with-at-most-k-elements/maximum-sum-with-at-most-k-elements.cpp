class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
     priority_queue<pair<int,int>>sachu;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sachu.push({grid[i][j],i});
            }
        }
        long long ans=0;
        // sort(sachu.begin(),sachu.end());
        vector<int>count(limits.size(),0);
        while(!sachu.empty()){
            if(count[sachu.top().second]<limits[sachu.top().second]&&k){
                ans+=sachu.top().first;
                k--;
                count[sachu.top().second]++;
            }
            sachu.pop();

        }
        return ans;
    }

};