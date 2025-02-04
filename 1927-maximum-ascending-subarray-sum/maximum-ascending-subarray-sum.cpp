class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, asc = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                asc += nums[i];  
            } else {
                ans = max(ans, asc); 
                asc = nums[i];  
            }
        }
        return max(ans, asc);
    }
};
