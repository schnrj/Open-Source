class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        int grps=n/k;
        if(n%k!=0) return false;
        unordered_map<int,int>mp;
        for(auto v:nums) mp[v]++;

        for(auto p:mp){
            if(p.second>grps) return false;
        }
        return true;
    }
};