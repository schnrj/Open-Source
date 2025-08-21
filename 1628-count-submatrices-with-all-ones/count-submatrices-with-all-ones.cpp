class Solution {
public:
int count(vector<int>&v){
    int temp=0;
    int res=0;
    for(auto x:v){
        if(x==0){
            temp=0;
        }
        else{
            temp++;
        }
        res+=temp;
    }
    return res;
}
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;

        for(int sr=0;sr<m;sr++){
                
             vector<int>col(n,1);   
            for(int er=sr;er<m;er++){
               
               for(int i=0;i<n;i++){
                col[i]=col[i]&mat[er][i];
               }
               ans+=count(col);
            }
        }
        return ans;
    }
};