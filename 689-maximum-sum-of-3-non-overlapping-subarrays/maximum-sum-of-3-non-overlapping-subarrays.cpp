class Solution {
public:
    int sum(vector<int>& nums, int i, int count, int k, vector<int>& pref,vector<vector<int>>&dp) {
        if (count == 0) return 0;
        if (i + k > nums.size()) return INT_MIN;
        if(dp[i][count]!=-1) return dp[i][count];

        int take = pref[i + k] - pref[i] + sum(nums, i + k, count - 1, k, pref,dp);
        int notTake = sum(nums, i + 1, count, k, pref,dp);

        dp[i][count] =max(take, notTake);
        return dp[i][count];
    }

   void solve(vector<int>& nums, vector<int>& res, int i, int count, int k, vector<int>& pref,vector<vector<int>>&dp) {
        if (count == 0) return;
        //  dp[i][count];
        if (i + k > nums.size()) return ; 
        // dp[i][count];
        // if(dp[i][count]!=-1) return dp[i][count];

        int take = pref[i + k] - pref[i] + sum(nums, i + k, count - 1, k, pref,dp);
        int notTake = sum(nums, i + 1, count, k, pref,dp);

        if (take >= notTake) {
            res.push_back(i);
            // dp[i][count]=
            solve(nums, res, i + k, count - 1, k, pref,dp);
        } else {
        //    dp[i][count] =
           solve(nums, res, i + 1, count, k, pref,dp);
        }
        // return dp[i][count];
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> pref(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
vector<vector<int>>dp(nums.size()+1,vector<int>(4,-1));
        vector<int> res;
        solve(nums, res, 0, 3, k, pref,dp);
        return res;
    }
};
