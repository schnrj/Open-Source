class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int count=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
             if(nums[r]==0) count++;
           while(count>1&&l<nums.size()&&r<nums.size()){
            if(nums[l]==0){
                count--;
            }
            l++;
           }
           ans=max(ans,r-l);
        }
        return ans;      
    }
};