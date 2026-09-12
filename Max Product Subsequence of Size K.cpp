class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        // sort an array
        sort(arr.begin(),arr.end());
        int prod=1;
        // when max num in arr is 0 and k is odd
        if(arr[n-1]==0 && k%2!=0){
            return 0;
        }
        // when all nums in arr are neg and k is odd 
        if(arr[n-1]<0 && k%2!=0){
            for(int i=n-1;i>=n-k;i--){
                prod*=arr[i];
            }
            return prod;
        }
        // when k is odd for general
        int l=0;
        int r=n-1;
        if(k%2!=0){
            prod*=arr[r];
            r--;
            k--;
        }
        // now apply for even case which is same for all cases
         k=k/2; // to make even pairs
        for(int i=0;i<k;i++){
            int leftprod=arr[l]*arr[l+1];
            int rightprod=arr[r]*arr[r-1];
            if(leftprod>rightprod){
                prod*=leftprod;
                l+=2;
            }else{
                prod*=rightprod;
                r-=2;
            }
        }
        return prod;
    }
};