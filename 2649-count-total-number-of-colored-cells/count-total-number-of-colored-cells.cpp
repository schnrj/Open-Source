class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long coloredCells(int n) {
        return 1LL + 2LL * (n - 1) * n;
    }
};
