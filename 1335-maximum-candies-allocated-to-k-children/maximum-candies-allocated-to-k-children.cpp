class Solution {
public:
    bool possible(vector<int>& candies, long long k, long long mid) {
        long long count = 0;
        for (auto x : candies) {
            count += x / mid;
            if (count >= k) return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = accumulate(candies.begin(), candies.end(), 0LL);
        if (totalCandies < k) return 0;

        long long l = 1, r = totalCandies / k, ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (possible(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
