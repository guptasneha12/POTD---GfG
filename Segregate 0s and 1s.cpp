class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int count0=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) count0++;
        }
        // fill it with 0;
        for(int i=0;i<count0;i++){
            arr[i]=0;
        }
        for(int i=count0;i<n;i++){
            arr[i]=1;
        }
        
    }
};