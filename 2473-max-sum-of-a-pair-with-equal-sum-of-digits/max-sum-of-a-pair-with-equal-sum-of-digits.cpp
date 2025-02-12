class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int>mp;
        int ans = -1;

        for(auto &e: nums){
            int curr_sum = 0, num = e;
            while(num){
                curr_sum += num%10;
                num/=10;
            }

            if(mp.find(curr_sum) != mp.end()){
            
                ans = max(ans, e + mp[curr_sum]); 
               
                mp[curr_sum] = max(e, mp[curr_sum]);
            }else mp[curr_sum] = e;
        }
        return ans;
    }
};