class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int>pre(nums.size(),nums[0]);
        vector<int>suff(nums.size(),nums[nums.size()-1]);
        int lm=nums[0];

        for(int i=1;i<nums.size();i++){
           lm=max(lm,nums[i]);
           pre[i]=lm;
        }

        int rm=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
           rm=min(rm,nums[i]);
           suff[i]=rm;
        }
        int ans=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>pre[i-1]&&nums[i]<suff[i+1]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1]){
                ans+=1;
            }
        }
        return ans;
    }
};