class Solution {
public:
   int kadane(vector<int>&nums){
    int curr=0;
    int maxsum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        if(curr>maxsum){
            maxsum=curr;
        }
        if(curr<0) curr=0;
    }
    return maxsum;
   }
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int>revnums(nums.size());
        for(int i=0;i<nums.size();i++){
           if(nums[i]>0) revnums.push_back((-1)*nums[i]);
           else revnums.push_back(abs(nums[i]));
        }
        int x1=kadane(nums);
        int x2=kadane(revnums);
        return max(x1,x2);
    }
};