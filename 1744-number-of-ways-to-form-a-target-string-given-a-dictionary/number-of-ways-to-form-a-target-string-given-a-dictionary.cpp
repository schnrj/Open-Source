class Solution {
public:
    int MOD = 1000000007;

    int solve(vector<vector<int>>& mp, string& target, vector<vector<int>>& dp, int i, int t) {
        if (t == target.size()) 
            return 1;
        if (i >= mp.size()) 
            return 0;
        if (dp[i][t] != -1) 
            return dp[i][t];
        int nottake = solve(mp, target, dp, i + 1, t) % MOD;
        int take = 0;
        if (mp[i][target[t] - 'a'] > 0) {
            take = (1LL * mp[i][target[t] - 'a'] * solve(mp, target, dp, i + 1, t + 1)) % MOD;
        }
        dp[i][t] = (nottake + take) % MOD;
        return dp[i][t];
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>> mp(n, vector<int>(26, 0));
        for (string& word : words) {
            for (int j = 0; j < word.size(); j++) {
                mp[j][word[j] - 'a']++;
            }
        }
        vector<vector<int>> dp(n, vector<int>(target.size(), -1));
        return solve(mp, target, dp, 0, 0);
    }
};
