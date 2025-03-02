class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<vector<int>>ans;
       for(int i=0;i<nums.size();i++){
        vector<int>sub;
        sub.push_back(nums[i]);
        if(k==1) ans.push_back(sub);
        for(int j=i+1;j<nums.size();j++){
            sub.push_back(nums[j]);
            if(sub.size()==k){
                ans.push_back(sub);
            }
        }
       }
       vector<set<int>>s;
for(int i=0;i<ans.size();i++){
    set<int>temp;
    for(int j=0;j<ans[i].size();j++){
        temp.insert(ans[i][j]);
    }

    s.push_back(temp);
}
// for(int i=0;i<s.size();i++){
//     for(int j=0;j<s[i].size();j++){
//         cout<s[i][j]<<" ";
//     }
// }
       map<int,int>mp;
       for(int i=0;i<s.size();i++){
        set<int>s1=s[i];
       for (auto it = s1.begin(); it != s1.end(); ++it) {
    mp[*it]++;
    }
        
       }
       int sachu=INT_MIN;
       for(auto p:mp){
        if(p.second==1){
            sachu=max(sachu,p.first);
        }
       }
       return sachu==INT_MIN?-1:sachu;
    return 1;
    }
};