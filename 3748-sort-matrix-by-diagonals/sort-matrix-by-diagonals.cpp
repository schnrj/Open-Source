class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         int n = grid.size();

   
        for (int i = 0; i < n; i++) {
            vector<int> diag;
            int row = i, col = 0;

         
            while (row < n && col < n) {
                diag.push_back(grid[row][col]);
                row++;
                col++;
            }

  
            sort(diag.rbegin(), diag.rend());

    
            row = i, col = 0;
            for (int val : diag) {
                grid[row][col] = val;
                row++;
                col++;
            }
        }

      
        for (int j = 1; j < n; j++) {
            vector<int> diag;
            int row = 0, col = j;

           
            while (row < n && col < n) {
                diag.push_back(grid[row][col]);
                row++;
                col++;
            }

            
            sort(diag.begin(), diag.end());

            
            row = 0, col = j;
            for (int val : diag) {
                grid[row][col] = val;
                row++;
                col++;
            }
        }

        return grid;
    }
};