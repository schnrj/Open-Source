class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto v:nums){
            mp[v]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
       for(auto p:mp){
        pq.push({p.second,p.first});
        if(pq.size()>k){
            pq.pop();
        }
        
       }
       vector<int>ans;
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       return ans;
    }
};