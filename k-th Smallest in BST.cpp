
 // inorder
  void inorder(Node* root,int &k,int &res){
      if(root==NULL) return;
      inorder(root->left,k,res);
      k--;    // process the current node
      if(k==0){
          res=root->data;
          return;
      }
      inorder(root->right,k,res);
  }
  
  
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        int res=-1;
        inorder(root,k,res);
        return res;
    }