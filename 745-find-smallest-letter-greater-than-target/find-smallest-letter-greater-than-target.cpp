class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo=-1,hi=letters.size();
        while(lo+1<hi){
            int mid=lo+(hi-lo)/2;
            if(letters[mid]>target){
                hi=mid;
            }
            else lo=mid;
        }
        if(hi==letters.size()) return letters[0];
        return letters[hi];
    }
};