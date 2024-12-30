class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int low, int high, int zero, int one, int length, std::vector<int>& dp) {
        if (length > high) return 0;

        if (dp[length] != -1) return dp[length];

        int count = (length >= low) ? 1 : 0;

        count = (count + solve(low, high, zero, one, length + zero, dp)) % MOD;
        count = (count + solve(low, high, zero, one, length + one, dp)) % MOD;

        return dp[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        std::vector<int> dp(high + 1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};
