class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int i = 0;
        int n = nums.size();
        unordered_map<int, int> bit;

        for (int j = 0; j < n; j++) {
            bool f = false;
            for (int k = 0; k < 32; k++) {
                if (nums[j] & (1 << k)) {
                    bit[k]++;
                }
                if (bit[k] > 1) {
                    f = true;
                }
            }

            while (f) {
                for (int k = 0; k < 32; k++) {
                    if (nums[i] & (1 << k)) {
                        bit[k]--;
                    }
                }
                i++;
                f = false;
                for (int k = 0; k < 32; k++) {
                    if (bit[k] > 1) {
                        f = true;
                        break;
                    }
                }
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
