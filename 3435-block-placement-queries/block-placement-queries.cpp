

class BIT {
public:
    int n;
    vector<int> l;

    BIT(int n) {
        this->n = n;
        l.assign(n + 2, 0); 
    }

    void add(int i, int x) {
        i += 1;
        while (i <= n) {
            l[i] = max(l[i], x);
            i += i & -i;
        }
    }

    int query(int i) {
        i += 1;
        int ans = 0;
        while (i > 0) {
            ans = max(ans, l[i]);
            i -= i & -i;
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> sl;
        int n = min(50000, (int)queries.size() * 3);
        sl.insert(0);
        sl.insert(n);

        vector<pair<int, int>> segments;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                sl.insert(x);
            }
        }

        BIT bit(n + 1);

       
        vector<int> svec(sl.begin(), sl.end());
        for (size_t i = 1; i < svec.size(); ++i) {
            int x = svec[i - 1], y = svec[i];
            bit.add(y, y - x);
        }

        vector<bool> ans;
        reverse(queries.begin(), queries.end());

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = sl.find(x);
                auto after = next(it);
                auto before = prev(it);
                sl.erase(it);
                bit.add(*after, *after - *before);
            } else {
                int x = q[1], sz = q[2];
                auto it = sl.upper_bound(x);
                auto before = prev(it);
                bool ok = (bit.query(*before) >= sz || (x - *before) >= sz);
                ans.push_back(ok);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
