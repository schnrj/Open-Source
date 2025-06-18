class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sachu;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i+2] - nums[i] <= k) {
                sachu.push_back({nums[i], nums[i+1], nums[i+2]});
            } else {
                return {};
            }
        }
        return sachu;
    }
};
