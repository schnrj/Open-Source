class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       int n = nums.size();

    
    for (int a = 0; a + 2 * k <= n; a++) {
        bool first_inc = true, second_inc = true;

        
        for (int i = a; i < a + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                first_inc = false;
                break;
            }
        }

        
        for (int i = a + k; i < a + 2*k - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                second_inc = false;
                break;
            }
        }

        if (first_inc && second_inc)
            return true;
    }

        return false;
    }
};