class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>sachu(n + 1,0);


        for (auto& q:queries) {
            int l = q[0], r = q[1];
            sachu[l] += 1;
            if (r + 1 < n) {
                sachu[r + 1] -= 1;
            }
        }

        
        for (int i = 1; i < n; ++i) {
            sachu[i]+=sachu[i - 1];
        }

        
        for (int i = 0; i < n; ++i) {
            if (nums[i]>sachu[i]) {
                return false; 
            }
        }

        return true;
    }
};
