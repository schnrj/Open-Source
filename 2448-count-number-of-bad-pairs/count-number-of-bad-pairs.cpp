class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = i - nums[i];
            count += mp[x];  
            mp[x]++;  
        }

        int n = nums.size();
        long long total = (1LL * n * (n - 1)) / 2;
        return total - count; 
    }
};
