class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here
        int sum=0;
        for(auto &it:adj){
            sum+=it.size();
        }
        return sum/2;
    }
};