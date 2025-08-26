class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxd=0.0;
        int maxa=0;
// cout<<sqrt(16)<<"";
        for(int i=0;i<dimensions.size();i++){
            double tempd=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            if(tempd>maxd){
                maxd=tempd;
                maxa=dimensions[i][0]*dimensions[i][1];
            }
            if(tempd==maxd){
                maxa=max(maxa,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxa;
    }
};