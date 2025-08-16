class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int flag=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i) flag=flag&nums[i];
        }
        return flag==INT_MAX?0:flag;
    }
};