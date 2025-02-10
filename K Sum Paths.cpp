class Solution {
  public:
  
  void solve(Node* root,int k,int &cnt,vector<int> &path){
      // base case
      if(root==NULL) return;
      
      path.push_back(root->data);
      // left call
      solve(root->left,k,cnt,path);
      // right call
      solve(root->right,k,cnt,path);
      
      int n=path.size();
      int sum=0;
      for(int i=n-1;i>=0;i--){
          sum+=path[i];
          if(sum==k) cnt++;
      }
      // backtrack
      path.pop_back();
  }
  
  
  
  
    int sumK(Node *root, int k) {
        // code here
        vector<int> path;
        int cnt=0;
        solve(root,k,cnt,path);
        return cnt;
    }
};
