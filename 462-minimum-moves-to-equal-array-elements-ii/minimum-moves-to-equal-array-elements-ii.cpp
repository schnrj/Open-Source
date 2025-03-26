class Solution {
public:
    int minMoves2(vector<int>& nums) {
         vector<int>sachu=nums;
        bool f=false;
        int x=1;
        // int r=grid[0][0]%x;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[i].size();j++){
        //         if(grid[i][j]%x!=r) return -1;
        //         else sachu.push_back(grid[i][j]);
        //     }
        // }
        sort(sachu.begin(),sachu.end());
        int ans=0;
        int mid=sachu.size()/2;
        for(auto v:sachu){
            ans+=(abs(v-sachu[mid])/x);
        }
        return ans;
    }
};