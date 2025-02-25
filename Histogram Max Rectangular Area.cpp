class Solution {
  public:
  
  vector<int> nextsmaller(vector<int> &arr){
      int n=arr.size();
      stack<int> st;
      vector<int> ans(n);
      st.push(-1);
      
      for(int i=n-1;i>=0;i--){
          while(st.top()!=-1 && arr[st.top()]>=arr[i]){
             st.pop();
          }
          ans[i]=st.top();
          st.push(i);
          
      }
      return ans;
  }
  
  
  vector<int> prevsmaller(vector<int> &arr){
      int n=arr.size();
      stack<int> st;
      vector<int> ans(n);
      st.push(-1);
      for(int i=0;i<n;i++){
          while(st.top()!=-1 && arr[st.top()]>=arr[i]){
              st.pop();
          }
          ans[i]=st.top();
          st.push(i);
      }
      return ans;
  }
  
  
    int getMaxArea(vector<int> &arr) {
        int n=arr.size();
        // find next and prev smaller element
        vector<int> next=nextsmaller(arr);
        vector<int> prev=prevsmaller(arr);
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            int l=arr[i];
            if(next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            int area=l*b;
            maxarea=max(maxarea,area);
        }
        
        return maxarea;
    }
};
