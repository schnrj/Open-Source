class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
          pre[i]=pre[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
        long long left=pre[i];
            long long right=pre[nums.size()-1]-pre[i];
            if(left>=right) ans++;
        }
        return ans;
    }
};