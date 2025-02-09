class Solution {
  public:
  
  
  int solve(Node* root,int &sum){
      if(root==NULL) return 0;
      int l=max(0,solve(root->left,sum));
      int r=max(0,solve(root->right,sum));
      
      sum=max(sum,l+r+root->data);
      return root->data+max(l,r);
  }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int sum=root->data;
        solve(root,sum);
        return sum;
    }
};