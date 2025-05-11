class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()==0||arr.size()==1||arr.size()==2) return false;
        for(int i=0;i<arr.size()-2;i++){
           int x=arr[i]%2;
           int y=arr[i+1]%2;
           int z=arr[i+2]%2;
           if(x&&y&&z){
            return true;
           }
        }
        return false;
    }
};