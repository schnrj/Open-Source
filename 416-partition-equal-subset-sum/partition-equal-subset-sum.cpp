class Solution {
public:
    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return dp[i][target] = true;
        }        
        if (i >= nums.size()) {
            return dp[i][target] = false;
        }
        if (dp[i][target] != -1) return dp[i][target];
        
        if (nums[i] > target) 
            return dp[i][target] = solve(nums, i + 1, target, dp);
        else 
            return dp[i][target] = solve(nums, i + 1, target - nums[i], dp) || solve(nums, i + 1, target, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target + 1, -1));  
        
        return solve(nums, 0, target, dp);
    }
};
