class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        // SOLUTION -1
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[j-1]){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
        
        
        
        // SOLUTION-2
        int n=arr.size();
        int cnt=0;
        int l=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                l++;
            }
            else{
                cnt+=(l*(l-1))/2;
                l=1;
            }
        }
        cnt+=(l*(l-1))/2;
        return cnt;
        
    }
};
