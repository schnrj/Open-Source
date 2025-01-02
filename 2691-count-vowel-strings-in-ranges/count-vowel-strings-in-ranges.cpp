class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size(), 0);
        int count = 0;

      
        for (int i = 0; i < words.size(); i++) {
            char first = words[i][0], last = words[i].back();
            if ((first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') &&
                (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u')) {
                count++;
            }
            prefix[i] = count;
        }

        vector<int> ans;

     
        for (const auto& query : queries) {
            int start = query[0], end = query[1];
            if (start == 0) {
                ans.push_back(prefix[end]);
            } else {
                ans.push_back(prefix[end] - prefix[start - 1]);
            }
        }

        return ans;
    }
};
