class Solution {
public:
int solve(vector<int>&nums,int k){
     unordered_map<int, int> freq;
        int i = 0, count = 0;

        for (int j = 0; j < nums.size(); ++j) {
            if (freq[nums[j]] == 0) k--;
            freq[nums[j]]++;

            while (k < 0) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) k++;
                i++;
            }

            count += j - i + 1;
        }

        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
        
    }
};