class Solution {
public:
   vector<int>seg;
   void build(int node,int s,int e,vector<int>&baskets){
       if(s==e){
        seg[node]=baskets[s];
        return;
       }
    int mid=s+(e-s)/2;
       build(2*node,s,mid,baskets);
       build(2*node+1,mid+1,e,baskets);
       seg[node]=max(seg[2*node],seg[2*node+1]);
   }
   int search(int node,int s,int e,vector<int>&baskets,int f){
    if(seg[node]<f) return -1;
    if(s==e){
        seg[node]=-1;
        return s;
    }
    int mid=s+(e-s)/2;
    int idx=seg[2*node]>=f?search(2*node,s,mid,baskets,f):search(2*node+1,mid+1,e,baskets,f);
    seg[node]=max(seg[2*node],seg[2*node+1]);
    return idx;
   }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        seg.resize(4*n,INT_MIN);
        
        build(1,0,n-1,baskets);

        int ans=0;
        for(int i=0;i<fruits.size();i++){
            if(search(1,0,n-1,baskets,fruits[i])==-1){
                ans++;
            }
        }
        return ans;
    }
};