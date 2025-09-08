class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
    //     vector<int>nge(n,n);
    //     stack<int>st;

    //     for(int i=0;i<n;i++){
    //         while(!st.empty()&&nums[st.top()]<nums[i]){
    //             nge[st.top()]=i;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     // for(int i=0;i<n;i++) cout<<nge[i]<<" ";
         
    //      vector<int>ans(n);
    //     for(int i=0;i<n;i++){
    //         int l=nge[i]+1;
    //         while(l<n&&nums[i]>=nums[l]){
    //             l=nge[l];
    //         }
    //         if(l>=n) ans[i]=-1;
    //         else ans[i]=nums[l];
    //     }
    //    return ans;
     vector<int> ans(n, -1);
        stack<int> s1, s2, temp;

        for (int i = 0; i < n; i++) {
            while (!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push(s1.top());
                s1.pop();
            }
            while (!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }

        return ans;
    }
};