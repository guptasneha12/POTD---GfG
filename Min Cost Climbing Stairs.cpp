class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
          int n = cost.size();
    
    if (n==1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];
    
    for (int i=2; i<n; i++) {
        int curr = cost[i] + 
        min(prev1, prev2);
        
        prev2 = prev1;
        prev1 = curr;
    }
    
  
    return min(prev1, prev2);
    }
};