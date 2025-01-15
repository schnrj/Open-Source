class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c2 = __builtin_popcount(num2);
        string nums1 = bitset<32>(num1).to_string();
        string x(32, '0');
        
        for (int i = 0; i < 32 && c2 > 0; i++) {
            if (nums1[i] == '1') {
                x[i] = '1';
                c2--;
            }
        }
        
        for (int i = 31; i >= 0 && c2 > 0; i--) {
            if (x[i] == '0') {
                x[i] = '1';
                c2--;
            }
        }
        
        int result = bitset<32>(x).to_ulong();
        return result;
    }
};