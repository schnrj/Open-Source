class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count1, count2, total;
        for (int x : basket1) {
            count1[x]++;
            total[x]++;
        }
        for (int x : basket2) {
            count2[x]++;
            total[x]++;
        }

        for (auto& [k, v] : total) {
            if (v % 2 != 0) return -1;
        }

        vector<int> diff;
        for (auto& [val, _] : total) {
            int target = total[val] / 2;
            int in1 = count1[val];
            int in2 = count2[val];
            if (in1 > target) {
                for (int i = 0; i < in1 - target; ++i) diff.push_back(val);
            } else if (in2 > target) {
                for (int i = 0; i < in2 - target; ++i) diff.push_back(val);
            }
        }

        sort(diff.begin(), diff.end());
        int mini = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        long long res = 0;
        for (int i = 0; i < diff.size() / 2; ++i) {
            res += min(diff[i], 2 * mini);
        }

        return res;
    }
};
