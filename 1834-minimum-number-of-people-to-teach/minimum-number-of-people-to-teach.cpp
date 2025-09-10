class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int,int> mp;
        unordered_set<int> sad;

        for (int i = 0; i < friendships.size(); i++) {
            int f1 = friendships[i][0];
            int f2 = friendships[i][1];
            vector<int> l = languages[f1-1];
            vector<int> l2 = languages[f2-1];
           
            bool f = false;
            for (int k = 0; k < l.size(); k++) {
                if (find(l2.begin(), l2.end(), l[k]) != l2.end()) {  
                    f = true;
                    break;
                }
            }

            if (f) continue;
            sad.insert(f1);
            sad.insert(f2);
        }

        if (sad.empty()) return 0;

        for (int person : sad) {
            for (int lang : languages[person-1]) {
                mp[lang]++;
            }
        }

        int maxl = 0;
        for (auto &p : mp) {
            if (p.second > maxl) {
                maxl = p.second;
            }
        }

        return sad.size() - maxl;
    }
};
