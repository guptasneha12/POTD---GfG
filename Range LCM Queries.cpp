#define ll long long int
class Solution {
  public:
  ll lcm(ll a, ll b){
      return (a*b)/__gcd(a,b);
  }
  
  // build segment treee
  void build(int node, int start, int end, vector<ll> &segtree, vector<int> &arr){
      if(start==end){
          segtree[node]=arr[start];
          return;
      }
      // traverse in left and right side
      int mid=(start+end)/2;
      build(2*node,start,mid,segtree,arr);
      build(2*node+1,mid+1,end,segtree,arr);
      // update the value on moving upward
      segtree[node]=lcm(segtree[2*node],segtree[2*node+1]);
  }
  
  // update the value of node
  void update(int node,int start, int end, int idx,int val, vector<ll> &segtree){
      if(start==end){
          segtree[node]=val;
          return;
      }
      int mid=(start+end)/2;
      if(idx<=mid)
      update(2*node,start,mid,idx,val,segtree);
      else
      update(2*node+1,mid+1,end,idx,val,segtree);
      // on moving upward store the newly update lcm of left and right with updated value
      segtree[node]=lcm(segtree[2*node],segtree[2*node+1]);
  }
  
  //perform query
  long long query(int node,int start,int end,int l, int r, vector<long long> &segtree){
      // out of range 
      if(r<start || end<l){
          return 1;
      }
      if(l<=start && end<=r){
          return segtree[node];
      }
      // in case of overlapping
      int mid=(start+end)/2;
      ll left=query(2*node,start,mid,l,r,segtree);
      ll right =query(2*node+1,mid+1,end,l,r,segtree);
      return lcm(left,right);
  }
  
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<ll> segtree(4*n);
        build(1,0,n-1,segtree,arr);
        vector<ll> ans;
        for(auto &q:queries){
            // update the value
            if(q[0]==1){
                int idx=q[1];
                int val=q[2];
                update(1,0,n-1,idx,val,segtree);
            }
            else{
                int l=q[1];
                int r=q[2];
                ans.push_back(query(1,0,n-1,l,r,segtree));
            }
        }
        return ans;
        
    }
};