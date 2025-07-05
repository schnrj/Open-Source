class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
       __int128 len = 1;  
  for (int op : operations) {
           len*=2;
        }
      

        int shift = 0;
        for (int i = operations.size() - 1; i >= 0; --i) {
            len /= 2;
            if (k > len) {
                k -= len;
                if (operations[i] == 1) {
                    shift += 1;
                }
            } else {
            }
        }

      
        char base = 'a';
        char result = (base - 'a' + shift) % 26 + 'a';
        return result;
    }
};
