class Solution {
public:
// int ans=0;
int MOD=1e9+7;
    int solve(int i,int target,vector<vector<int>>&types,vector<vector<int>>&dp){
       if(target==0) return 1;
       if(i==types.size()) return 0;
       if(dp[i][target]!=-1) return dp[i][target];

       int ans=0;
       for(int k=0;k<=types[i][0];k++){
        int score=k*types[i][1];
        if(score>target) break;

        ans+=solve(i+1,target-score,types,dp)%MOD;
        ans%=MOD;
       }
        

        return dp[i][target]=ans;

    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {

        vector<vector<int>>dp(types.size(),vector<int>(target+1,-1));
        
        return solve(0,target,types,dp);
    }
};