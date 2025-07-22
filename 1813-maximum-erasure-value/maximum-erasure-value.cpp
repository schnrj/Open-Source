class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int i = 0, j = 0, sum = 0, maxSum = 0;
        int n = nums.size();

        while (j < n) {
            if (seen.find(nums[j]) == seen.end()) {
                sum += nums[j];
                seen.insert(nums[j]);
                maxSum = max(maxSum, sum);
                j++;
            } else {
                
                sum -= nums[i];
                seen.erase(nums[i]);
                i++;
            }
        }
        return maxSum;
    }
};
