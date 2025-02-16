class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        sort(arr.begin(),arr.end());
        vector<int> res;
        int n=arr.size();
        int size=n-k;
        for(int i=n-1;i>=size;i--){
            res.push_back(arr[i]);
        }
        return res;
    }
};