class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int total = 0;
    for (int n : nums) total += n;

    int maxLen = -1, curr = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
        curr += nums[r];
        while (l <= r && curr > total - x) {
            curr -= nums[l++];
        }
        if (curr == total - x) {
            maxLen = max(maxLen, r - l + 1);
        }
    }

    return maxLen == -1 ? -1 : nums.size() - maxLen;
}

};