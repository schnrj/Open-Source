class Solution {
public:
    int find(int val,vector<pair<int,int>>&p){
        int l=0;
        int r=p.size()-1;
        int mid;
        int res=0;
        while(l<=r){
          mid=l+(r-l)/2;
            pair<int,int>sachu=p[mid];
            if(sachu.first<=val){
                res=sachu.second;
                l=mid+1;

            }
            else{
                r=mid-1;
            }
        }
       return res;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>p;
        int ans=0;
        for(int i=0;i<difficulty.size();i++){
            p.push_back({difficulty[i],profit[i]});
        }
sort(p.begin(),p.end());
        for (int i = 1; i < p.size(); i++) {
        p[i].second = max(p[i].second, p[i-1].second);
    }
        
        for(int i=0;i<worker.size();i++){
            ans+=find(worker[i],p);
        }
        return ans;
        
    }
};