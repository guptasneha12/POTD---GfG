class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        // BRUTE FORCE
        // int n=arr.size();
        // int cnt=0;
        // for(int i=0;i<n/2;i++){
        //     for(int j=n/2;j<n;j++){
        //         if(arr[i]>=5*arr[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
        //OPTIMISED APPROACH
        int n=arr.size();
        int cnt=0;
        // sort first half of array
        sort(arr.begin(),arr.begin()+n/2);
        // sort 2nd half of array
        sort(arr.begin()+n/2,arr.end());
        
        int r=n/2;
        for(int l=0;l<n/2;l++){
            while(r<n && arr[l]>=5*arr[r]){
                r++;
            }
            cnt+=(r-n/2);
        }
        return cnt;
    }
};