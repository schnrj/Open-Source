class Solution {
public:
    int solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return dp[i][target] = (target == 0 ? 0 : INT_MIN);
        }

        if (dp[i][target] != -1) return dp[i][target];  

        int take = INT_MIN;
        if (nums[i] <= target) {
            int temp = solve(nums, i + 1, target - nums[i], dp);
            if (temp != INT_MIN)
                take = 1 + temp;
        }

        int nottake = solve(nums, i + 1, target, dp);

        return dp[i][target] = max(take, nottake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = solve(nums, 0, target, dp);
        return ans < 0 ? -1 : ans;
    }
};
