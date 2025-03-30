class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int sidx=0;
        int currgas=0;
        
        for(int i=0;i<n;i++){
            currgas=currgas+gas[i]-cost[i];
            if(currgas<0){
                sidx=i+1;
                currgas=0;
            }
        }
        currgas=0;
        for(int i=0;i<n;i++){
            int idx=(i+sidx)%n;
            currgas=currgas+gas[idx]-cost[idx];
            if(currgas<0) return -1;
        }
        return sidx;
    }
};