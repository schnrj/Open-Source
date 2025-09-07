class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n+2,0);
        for(int i=0;i<bookings.size();i++){
            int l=bookings[i][0];
            int r=bookings[i][1];
            int val=bookings[i][2];
            ans[l]+=val;
            ans[r+1]+=(-1)*val;
        }
        // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        vector<int>sachu(n,0);
        sachu[0]=ans[1];
        for(int i=1;i<n;i++){
            sachu[i]=ans[i+1]+sachu[i-1];
        }
        return sachu;
    }
};