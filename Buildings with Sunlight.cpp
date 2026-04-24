class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n=arr.size();
        int cnt=1; // as 1st building will always gets sunlight
        int maxi=arr[0]; // this holds maximum value
        for(int i=1;i<n;i++){
            if(arr[i]>=maxi){
            cnt++;
            maxi=arr[i];
            }
        }
        return cnt;
    }
};