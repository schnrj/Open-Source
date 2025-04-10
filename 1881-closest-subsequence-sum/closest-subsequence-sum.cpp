class Solution {
    vector<int> findAllSums(vector<int>& nums,int start,int end,int offset){        
         vector<int> sums = {0}; 
    int l=end-start+1;
    for (int j=0;j<l;j++) {
        int n = sums.size();
        for (int i = 0; i < n; i++) {
            sums.push_back(sums[i] + nums[j+offset]);
        }
    }
    
    return sums;
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
    
        
        int n=nums.size();
        if(n==1)    return min(abs(goal),abs(nums[0]-goal));
        
  
        vector<int> firstHalf = findAllSums(nums,0,n/2-1,0);
        vector<int> secondHalf = findAllSums(nums,n/2,n-1,n/2);
        sort(secondHalf.begin(),secondHalf.end());
        
        int res=INT_MAX;
        for(int i=0;i<firstHalf.size();++i){
            int lb = lower_bound(secondHalf.begin(),secondHalf.end(),goal-firstHalf[i])-secondHalf.begin();
            
            if(lb>0)
                res=min(res,abs(goal-secondHalf[lb-1]-firstHalf[i]));
            if(lb<secondHalf.size())
                res=min(res,abs(goal-secondHalf[lb]-firstHalf[i]));
        }
        return res;
    }
};