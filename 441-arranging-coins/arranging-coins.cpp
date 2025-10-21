class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 1LL, hi = n + 1LL;
        while (lo + 1 < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long total = (mid * (mid + 1LL)) / 2;
            if (total <= n) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};