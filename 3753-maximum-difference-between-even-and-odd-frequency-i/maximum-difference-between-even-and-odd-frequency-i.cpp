class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        vector<int>e,o;
        for(auto p:mp){
            if(p.second%2!=0) o.push_back(p.second);
            else e.push_back(p.second);
        }
        int maxe=*max_element(e.begin(),e.end());
        int mine=*min_element(e.begin(),e.end());

        int maxo=*max_element(o.begin(),o.end());
        int mino=*min_element(o.begin(),o.end());
        int t1=mino-maxe;
        int t2=maxo-mine;
        int ans=max(t1,t2);
        return ans;

    }
};