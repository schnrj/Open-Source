class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n==1) return true;
        // long long  x=1;
        // while(x<n){
        //     x=x*4;

        // }
        // if(x==(long long)n) return true;
        // else return false;
        double res=log(n)/log(4);
        if(fabs(res-round(res))<1e-9){
            return true;
        }
        else return false;
    }
};