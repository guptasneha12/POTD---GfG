class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n=arr.size();
        int t=n; // since every child will get 1 candy each
        int i=1; // pointer
        while(i<n){
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            // for increasing sequence
            int inc=0;
            while(i<n && arr[i]>arr[i-1]){
                inc++;
                t+=inc;
                i++;
            }
            if(i==n){
                return t;
            }
            // for decreasing sequence
            int dec=0;
            while(i<n && arr[i]<arr[i-1]){
                dec++;
                t+=dec;
                i++;
            }
            // for repeating addition
            t-=min(inc,dec);
        }
        return t;
    }
};
