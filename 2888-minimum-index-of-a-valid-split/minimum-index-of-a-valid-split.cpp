class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int> pre(nums.size(), 0);
        unordered_map<int, int> mp;
        for (auto v : nums) mp[v]++;
        int maxi = INT_MIN, num, n = nums.size();
        for (auto p : mp) {
            if (p.second > maxi) {
                maxi = p.second;
                num = p.first;
            }
        }
        int pre_count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == num) pre_count++;
            int left = i + 1;
            int right = n - (i + 1);
            if (pre_count * 2 > left && (maxi - pre_count) * 2 > right) return i;
        }
        return -1;
    }
};
