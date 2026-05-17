class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
  vector<int> st;
  int n=arr.size();
  for(int i=0;i<n;i++){
      if(st.empty()){
          st.push_back(arr[i]);
      }
      // check for sign of elements
      else{
          bool topele=st.back()>=0;
          bool currele=arr[i]>=0;
          // opposite ele found
          if(topele!=currele){
              st.pop_back();
          }
          else{
              st.push_back(arr[i]);
          }
      }
  }
  return st;
        
    }
};