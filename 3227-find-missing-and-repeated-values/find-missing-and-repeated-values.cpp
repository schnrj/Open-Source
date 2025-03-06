class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector<int>ans;
        vector<int>sachu(grid.size()*grid.size()+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                   sachu[grid[i][j]]++;
            }
        }
        int a,b;
        for(int i=1;i<sachu.size();i++){
           if(sachu[i]==2) a=i;
           if(sachu[i]==0) b=i;
        }

        return {a,b};
    }
};