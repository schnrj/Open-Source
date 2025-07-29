class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
            vector<int>ans(nums.size(),1);
            for(int i=0;i<nums.size();i++){
               int x=nums[i];
               int j=i-1;
               while(j>=0&&(nums[j]|x)!=nums[j]){
                ans[j]=i-j+1;
                nums[j]|=x;
                j--;
               }
            }
            return ans;
    }
};