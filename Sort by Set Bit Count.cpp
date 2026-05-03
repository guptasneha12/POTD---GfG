class Solution {
  public:
  
  int countbits(int n){
      int cnt=0;
      while(n>0){
          cnt+=(n&1);
          n=n>>1;  // right shift 1
      }
      return cnt;
  }
  
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        auto comp= [&](int a, int b){
          int cnt1=countbits(a);
          int cnt2=countbits(b);
          return cnt1>cnt2;
        };
        // here we use stable sort for number of bits are same in 2 different numbers
        stable_sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};