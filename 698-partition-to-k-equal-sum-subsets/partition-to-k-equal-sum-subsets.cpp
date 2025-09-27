class Solution {
public:
    unordered_map<int, bool> dp; 
    
    bool help(int bucketNum, int bucketSum, int reqSum, int K, vector<int>& nums, int usedMask) {
        if (bucketNum == K + 1) return true;
        if (bucketSum == reqSum) {
            return help(bucketNum + 1, 0, reqSum, K, nums, usedMask);
        }
        if (dp.count(usedMask)) return dp[usedMask];

        for (int i = 0; i < nums.size(); i++) {
            if ((usedMask >> i) & 1) continue; 
            if (bucketSum + nums[i] > reqSum) continue;

            if (help(bucketNum, bucketSum + nums[i], reqSum, K, nums, usedMask | (1 << i))) {
                return dp[usedMask] = true;
            }
        }
        return dp[usedMask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int K) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % K != 0) return false;
        int reqSum = totalSum / K;

        dp.clear();
        return help(1, 0, reqSum, K, nums, 0);
    }
};
