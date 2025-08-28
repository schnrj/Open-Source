class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                int top=st.top();
                st.pop();
                ans[top]=i-top;
            }
            st.push(i);
        }
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        return ans;
    }
};