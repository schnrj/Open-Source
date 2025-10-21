class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1,mp2;
        for(auto x:nums1) mp1[x]++;
        for(auto x:nums2) mp2[x]++;
vector<int>ans;
        for(int i=0;i<=1000;i++){
            if(mp1.count(i)&&mp2.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};