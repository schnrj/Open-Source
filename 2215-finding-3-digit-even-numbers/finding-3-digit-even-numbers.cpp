class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && j != k && i != k) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (digits[i] != 0 && num % 2 == 0) {
                            st.insert(num);
                        }
                    }
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};
