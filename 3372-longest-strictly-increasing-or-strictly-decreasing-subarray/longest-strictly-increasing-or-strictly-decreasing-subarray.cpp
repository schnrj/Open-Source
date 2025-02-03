class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int inc=1;
        int dec=1;
        for(int i=1;i<nums.size();i++){
           inc=nums[i-1]<nums[i]?inc+1:1;
             dec=nums[i-1]>nums[i]?dec+1:1;
             ans=max({inc,dec,ans});
        }
        return ans;
    }
};