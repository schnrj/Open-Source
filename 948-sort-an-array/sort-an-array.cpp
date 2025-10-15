class Solution {
public:
    vector<int>merge(vector<int>&left,vector<int>&right){
        int l=left.size();
        int r=right.size();
        int i=0,j=0,k=0;
        int n=l+r;
        vector<int>ans(n);
        while(i<l&&j<r){
            if(left[i]<=right[j]){
                ans[k++]=left[i++];
            }
            else{
                ans[k++]=right[j++];
            }
        }
        while(i<l){
            ans[k++]=left[i++];
        }
        while(j<r){
            ans[k++]=right[j++];
        }
        return ans;
    }
    vector<int> merge_sort(int s,int e, vector<int>&nums){
        if(s==e) return {nums[s]};
        // if(s>=e) return nums[s];
        int mid=s+(e-s)/2;
        vector<int>left=merge_sort(s,mid,nums);
        vector<int>right=merge_sort(mid+1,e,nums);
        vector<int>ans=merge(left,right);
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        
        return merge_sort(0,nums.size()-1,nums);
        // return nums;
    }
};