class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        int q=queries.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        vector<int> res;
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int sum=prefix[r+1]-prefix[l];
            int count=(r-l+1);
            res.push_back(sum/count);
        }
        return res;
    }
};
