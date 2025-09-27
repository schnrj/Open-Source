class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(i>ans) return false;
            if(i+nums[i]>ans){
                ans=i+nums[i];
            }
            if(ans>=nums.size()-1) return true;
        }
        return false;
    }
};