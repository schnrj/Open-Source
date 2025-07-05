class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto v:arr){
            mp[v]++;
        }
    int ans=INT_MIN;
    for(auto p:mp){
        if(p.second==p.first) ans=max(ans,p.first);
    }
    return ans==INT_MIN?-1:ans;
    }
};