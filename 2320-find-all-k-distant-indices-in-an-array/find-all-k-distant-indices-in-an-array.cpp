class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
           
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
                if (nums[j] == key) {
                    ans.insert(i);
                    
                }
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
