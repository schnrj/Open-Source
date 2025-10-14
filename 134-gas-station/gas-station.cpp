class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gass=accumulate(gas.begin(),gas.end(),0);
        int costs=accumulate(cost.begin(),cost.end(),0);
        if(gass<costs) return -1;
        int total=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
        total=total+gas[i]-cost[i];
            if(total<0){
                total=0;
                ans=i+1;
            }
        }
        return ans;
    }
};