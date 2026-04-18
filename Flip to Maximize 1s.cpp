class Solution {
  public:
  
  int maxsum(vector<int> &arr){
      int n=arr.size();
      int sum=0;
      int maxi=0;
      for(int i=0;i<n;i++){
          sum+=arr[i];
          maxi=max(maxi,sum);
          if(sum<0) sum=0;
      }
      return maxi;
  }
    int maxOnes(vector<int>& arr) {
        // code here
        int n=arr.size();
        int onecnt=0;
        // make 1->-1 and 0->1
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                onecnt++;
                arr[i]=-1;
            }
            else arr[i]=1;
        }
        return onecnt+maxsum(arr);
        
    }
};