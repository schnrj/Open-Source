class Solution {
public:
int n;
   int bs(int val, vector<int>& power) {
    int l = 0, r = n - 1, ans = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (power[mid] > val) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

   long long solve(int i, vector<int>& power, unordered_map<int,long long>& mp, vector<long long>& dp) {
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];

    long long take = mp[power[i]];
    int idx;
    if (i + 1 < n) {
        idx = bs(power[i] + 2, power);
    } else {
        idx = n;
    }
    take += solve(idx, power, mp, dp);

    long long nottake = solve(i + 1, power, mp, dp);

    return dp[i] = max(take, nottake);
}

    long long maximumTotalDamage(vector<int>& power) {
      n=power.size();
        unordered_map<int,long long>mp;
        for(auto x:power){
            mp[x]+=x;
        }
        vector<long long>dp(n,-1LL);
        sort(power.begin(),power.end());
        return solve(0,power,mp,dp);
    }
};