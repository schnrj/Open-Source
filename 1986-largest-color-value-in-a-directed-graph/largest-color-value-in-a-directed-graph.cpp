class Solution {
    int dfs(int curr,vector<vector<int>>& adj,vector<int>& vis,vector<vector<int>>&dp,string& colors){
        if(vis[curr]==1)
            return INT_MAX;
        
        if(vis[curr]==0){
            vis[curr]=1;
            for(int nbr: adj[curr]){
                int res = dfs(nbr,adj,vis,dp,colors);
                if(res==INT_MAX)
                    return INT_MAX;
                
               
                for(int i=0;i<26;++i)
                    dp[i][curr] = max(dp[i][curr],dp[i][nbr]);
            }
            dp[colors[curr]-'a'][curr]++;
            vis[curr]=2;
        }
        return dp[colors[curr]-'a'][curr];
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        for(auto& edge: edges)
            adj[edge[0]].push_back(edge[1]);

        vector<vector<int>>dp(26,vector<int>(n));
        
        int ans = 0;
        vector<int>vis(n);
        
        for(int i=0;i<n;++i){
            int res = dfs(i,adj,vis,dp,colors);
            if(res==INT_MAX)
                return -1;
            ans= max(ans,res);
        }
        return ans;
    }
};