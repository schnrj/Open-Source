class Solution {
public:
vector<long long>dp;
// long long ans=0;
    long long solve(vector<vector<int>>&a,int i){
        if(i>=a.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=solve(a,i+a[i][1]+1)+a[i][0];
        long long nottake=solve(a,i+1);
        return dp[i]=max(take,nottake);
        // return ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.assign(questions.size(),-1);
        return solve(questions,0);        
    }
};