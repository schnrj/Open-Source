class Solution {
public:
int findMin(vector<int>& nums) {
    int l = -1, r = nums.size() - 1;
    int n=nums.size()-1;
    while (l+1<r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= nums[n]) 
           r=mid;
        else 
            l=mid;
    }
    return r;
}
int bs(vector<int>&nums,int lo,int hi,int target){
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;
}
    int search(vector<int>& nums, int target) {

        int mini=findMin(nums);
        if(target>=nums[mini]&&target<=nums[nums.size()-1]){
            return bs(nums,mini,nums.size()-1,target);
        }
        else{
            return bs(nums,0,mini-1,target);
        }
        
    }
};