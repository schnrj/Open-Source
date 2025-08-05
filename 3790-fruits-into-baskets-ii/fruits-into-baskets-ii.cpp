class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        set<int>s;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]&&s.find(j)==s.end()){
                    s.insert(j);
                    break;
                }
            }
        }
        return n-s.size();
    }
};