class Solution {

     int memo[501][501][2]; 

public:
    bool stoneGame(vector<int>& piles) {
        memset(memo, -1, sizeof(memo)); 
        return helper(0, piles.size() - 1, piles, 1) >= 0;
    }

    int helper(int l, int r, vector<int>& piles, int ID) {
        if (r < l) {
            return 0;
        }
        if (memo[l][r][ID] != -1) {
            return memo[l][r][ID];
        }

        int next = 1 - ID; 
        if (ID == 1) {
            memo[l][r][ID] = max(piles[l] + helper(l + 1, r, piles, next),
                                 piles[r] + helper(l, r - 1, piles, next));
        } else {
            memo[l][r][ID] = min(-piles[l] + helper(l + 1, r, piles, next),
                                 -piles[r] + helper(l, r - 1, piles, next));
        }

        return memo[l][r][ID];
    }
};