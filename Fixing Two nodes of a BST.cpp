class Solution {
  public:
  void findinorder(Node* root,vector<int> &inorder){
      if(root==NULL) return;
      findinorder(root->left,inorder);
      inorder.push_back(root->data);
      findinorder(root->right,inorder);
  }
  
  void solve(Node* root,vector<int> &inorder,int &index){
      if(root==NULL) return;
      solve(root->left,inorder,index);
      root->data=inorder[index];
      index++;
      solve(root->right,inorder,index);
  }
    void correctBST(Node* root) {
        // add code here.
        vector<int> inorder;
        findinorder(root,inorder);
        sort(inorder.begin(),inorder.end());
        int index=0;
        solve(root,inorder,index);
    }
};