class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < nums.size(); i++) {
            numIndex.push_back({nums[i], i});
        }

        
        sort(numIndex.begin(), numIndex.end(), greater<>());

      
        vector<pair<int, int>> topK(numIndex.begin(), numIndex.begin() + k);

       
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }
        return result;
    }
};