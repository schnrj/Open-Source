class Solution {
public:
    vector<int> divs, ans, path;

    void solve(int n, int k) {
        if (path.size() == k) {
            if (n != 1) return;
            if (ans.empty() || path.back() - path.front() < ans.back() - ans.front())
                ans = path;
            return;
        }
        for (auto x : divs) {
            if ((path.empty() || path.back() <= x) && n % x == 0) {
                path.push_back(x);
                solve(n / x, k);
                path.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        divs.clear();
        ans.clear();
        path.clear();

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i) divs.push_back(n / i);
            }
        }
        sort(divs.begin(), divs.end());

        solve(n, k);

        return ans;
    }
};
