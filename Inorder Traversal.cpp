class Solution {
  public:
  
  void solve(Node* root,vector<int> &res){
      // base case
      if(!root) return;
      solve(root->left,res);
      res.push_back(root->data);
      solve(root->right,res);
  }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> res;
        solve(root,res);
        return res;
        
    }
};