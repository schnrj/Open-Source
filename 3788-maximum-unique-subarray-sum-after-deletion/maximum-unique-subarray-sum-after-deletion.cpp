class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int p=0;
        int n=0;
        int negmax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mp[nums[i]]++;
            }
            if(nums[i]>=0) p++;
            else{
                negmax=max(negmax,nums[i]);
            } n++;
        }
        if(p==0){
            return negmax;
        }
        int ans=0;
        for(auto p:mp){
            ans+=p.first;
        }
        return ans;
    }
};