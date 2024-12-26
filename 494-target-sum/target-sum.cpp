class Solution {
public:
int res=0;
    void solve(vector<int>&nums,int target,int ans,int i){
        // if(i>=nums.size)
        if(i>nums.size()-1){
            if(ans==target) res++;
            return ;
            
        }
        solve(nums,target,ans+nums[i],i+1);
        solve(nums,target,ans-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
         solve(nums,target,0,0);
         return res;
    }
};