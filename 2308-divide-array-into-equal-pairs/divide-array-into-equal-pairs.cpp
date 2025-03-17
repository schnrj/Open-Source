class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        bool ans=true;
        for(auto p:mp){
            if(p.second%2==0){
                ans=true;
            }
            else{
                ans=false;
                break;
            }
        }
        return ans;
    }
};