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
    return nums[r];
}

};