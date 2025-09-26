class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=m*n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int nr=mid/n;
            int nc=mid%n;
            if(matrix[nr][nc]<target){
                l=mid+1;
            }
            else if(matrix[nr][nc]>target){
                r=mid-1;
            }
            else return true;
        }
        return false;
    }
};