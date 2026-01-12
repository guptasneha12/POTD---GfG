class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<pair<int,int>> pq; // to store ele in increasing order
        vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({arr[i],i}); // store ele and its index
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({arr[i],i});
            while(pq.top().second<=i-k){  // remove the ele from last index eg.0(2-2)
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};