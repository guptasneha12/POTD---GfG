class Solution {
  public:
  int cntkodd(vector<int>& arr, int k){
      int n=arr.size();
      int cnt=0,ans=0,start=0;
      // start holds the starting point of subarray
      for(int i=0;i<n;i++){
          if(arr[i]%2!=0) cnt++;
          while(cnt>k){
              if(arr[start]%2!=0)
              cnt--;
              start++;
          }
          ans+=i-start+1;
      }
      return ans;
  }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
      return cntkodd(arr,k)-cntkodd(arr,k-1);
    }
};