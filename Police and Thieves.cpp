class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int i=0,j=0,cnt=0;
        // use two pointer approach
        while(i<n && j<n){
            // i -> P
            // j -> T
            while(i<n && arr[i]!='P') i++;
            while(j<n && arr[j]!='T') j++;
            if(i<n && j<n && abs(i-j)<=k){
                cnt++;
                i++;
                j++;
            }
            else if(i<n && i<j) i++;
            else if(j<n && j<i) j++;
        }
        return cnt;
    }
};