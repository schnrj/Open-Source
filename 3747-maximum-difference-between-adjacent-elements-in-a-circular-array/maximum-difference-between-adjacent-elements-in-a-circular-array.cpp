class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
         vector<int> sachu(nums.begin(), nums.end());
        sachu.insert(sachu.end(), nums.begin(), nums.end());

        int ans = INT_MIN;
        
        for (int i = 0; i < sachu.size() - 1; i++) {
            ans = max(ans, abs(sachu[i + 1] - sachu[i]));
        }

        return ans;
    }
};