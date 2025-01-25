class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>sachu;
        for(int i=0;i<nums.size();i++){
            sachu.push_back({nums[i],i});
        }
        sort(sachu.begin(),sachu.end());

        int l=0;
        int r=1;
        while(r<nums.size()){
            vector<int> pos={sachu[l].second};
            while(r<nums.size()&&abs(sachu[r].first-sachu[r-1].first)<=limit){
                
                pos.push_back(sachu[r].second);
                r++;
            }
           
            sort(pos.begin(),pos.end());

            for(int i=0;i<r-l;++i)
                nums[pos[i]]=sachu[l+i].first;
            
            l=r;
            r++;
        }
        return nums;
    }
};