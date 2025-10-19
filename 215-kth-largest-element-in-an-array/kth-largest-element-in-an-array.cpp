class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         

         if(nums.size()<k) return -1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
         
        // // int count=0;
        // while(pq.size()!=1){
        // //   cout<<pq.top()<<" ";
        //   pq.pop();
        // }
        return pq.top();
        // return -1;
    }
};