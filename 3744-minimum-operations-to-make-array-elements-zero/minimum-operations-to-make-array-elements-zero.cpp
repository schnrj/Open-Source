class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;
        for(auto &v : queries) {
            long long L = v[0], R = v[1];
            long long sum = 0;
            long long maxi = 1;
            
            for (int i = 1; maxi <= R; i++){
                long long s = maxi;
                long long e = maxi * 4 - 1;
                long long l = max(L, s);
                long long r = min(R, e);
                if(l<=r)
                    sum += (long long)i * (r-l+1);
              
                if(maxi > R / 4) break;
                maxi *= 4;
            }
           
            total += (sum + 1) / 2;
        }
        return total;
    }
};
