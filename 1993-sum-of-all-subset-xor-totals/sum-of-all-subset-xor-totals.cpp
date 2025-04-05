class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orr=0;
        for(auto x:nums){
            orr|=x;
        }
        return orr*(1<<(nums.size()-1));
    }
};