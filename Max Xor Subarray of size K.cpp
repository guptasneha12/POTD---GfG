class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int currxor=0;
        // find xor of first k elements
        for(int i=0;i<k;i++){
            currxor^=arr[i];
        }
        int maxor=currxor;
        // now find in remaining n-k elements
        for(int i=k;i<n;i++){
            currxor^=arr[i];
            // to remove previous kth element
            currxor^=arr[i-k];
            maxor=max(maxor,currxor);
        }
        return maxor;
    }
};