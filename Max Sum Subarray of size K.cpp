class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        // use queue TC-O(n) SC-O(k)
        queue<int> q;
        int n=arr.size();
        int sum=0,maxsum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            q.push(arr[i]);
            
            if(q.size()>k){
                sum-=q.front();
                q.pop();
            }
            if(q.size()==k){
                maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }
};