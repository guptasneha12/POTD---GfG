class Solution {
  public:
  
  void inorder(Node* root,vector<int> &ans){
      if(root==NULL) return;
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
  
  
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        // use inorder traversal
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            if(ans[i]>=ans[i+1]) return false;
        }
        return true;
    }
};