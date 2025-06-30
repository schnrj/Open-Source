class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int ans=INT_MIN;
        while(i<n){
            int j=i+1;
            while(j<n&&nums[j]-nums[i]<=1){
                if(nums[j]-nums[i]==1) ans=max(ans,j-i+1);
                j++;
            }
            i++;
        }
        return ans==INT_MIN?0:ans;
    }
};