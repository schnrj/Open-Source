class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        long long  x=1;
        while(x<n){
            x=x*4;

        }
        if(x==(long long)n) return true;
        else return false;
    }
};