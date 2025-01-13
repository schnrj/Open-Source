class Solution {
public:
    int minimumLength(string s) {
      unordered_map<char,vector<int>>m;
      for(int i=0;i<s.size();i++){
        m[s[i]].push_back(i);
      }
      int ans=0;
      for(auto p:m){
        vector<int>v=p.second;
        int x=v.size();
        while(x>=3){
            ans=ans+2;
            x=x-2;
        }

      }
      return s.size()-ans;
      

    }
};
