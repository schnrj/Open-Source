class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ein=n/2;
        long long  oin=n%2==0?n/2:n/2+1;
         long long  eim=m/2;
        long long  oim=m%2==0?m/2:m/2+1;
        long long ans=ein*oim+oin*eim;
        
        
        
        return ans;
    }
};