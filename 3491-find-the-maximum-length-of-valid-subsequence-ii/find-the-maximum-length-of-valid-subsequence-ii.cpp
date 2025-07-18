class Solution {
public:
    // int solve(vector<int>& nums, int temp, int k, int i, int prev, vector<vector<int>>& dp) {
    //     if (i >= nums.size()) {
    //         return 0;
    //     }
    //     if (dp[i][prev + 1] != -1) {
    //         return dp[i][prev + 1];
    //     }

    //     int take = 0, nottake = 0;
    //     if (prev == -1 || (nums[i] + nums[prev]) % k == temp) {
    //         take = 1 + solve(nums, temp, k, i + 1, i, dp);
    //     }
    //     nottake = solve(nums, temp, k, i + 1, prev, dp);

    //     dp[i][prev + 1] = max(take, nottake);
    //     return dp[i][prev + 1];
    // }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(k,1)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int mod=(nums[i]+nums[j])%k;
                dp[i][mod]=max(dp[i][mod],1+dp[j][mod]);
                ans=max(ans,dp[i][mod]);
            }
        }

        return ans;
    }
};
