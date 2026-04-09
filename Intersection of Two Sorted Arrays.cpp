class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        while(i<n && j<m){
            // skip the duplicate
            if(i>0 && a[i-1]==a[i]){
                i++;
                continue;
            }
            if(a[i]<b[j]) i++;
            else if(a[i]>b[j]) j++;
            else{
                // for equal
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
  
    }
};