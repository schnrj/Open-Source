class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
       map<int,int>mp;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(auto v:nums){
            mp[v]++;
        }
        for(auto p:mp){
            if(p.second==1){
                if(mp.count(p.first-1)==0&&mp.count(p.first+1)==0) ans.push_back(p.first);
            }
        }
       
        return ans;
    }
};