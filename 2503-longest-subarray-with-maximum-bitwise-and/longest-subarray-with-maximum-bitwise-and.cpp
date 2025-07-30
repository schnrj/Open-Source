class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, cs = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = cs= 0;
            }

            if (maxVal == num) {
                cs++;
            } else {
                cs = 0;
            }

            ans = max(ans, cs);
        }
        return ans;
    }
};