class Solution {
  public:
  
  Node* solve(vector<int> &in, vector<int> &pre,int &idx,int start,int end,int n,unordered_map<int,int> &mp){
      // base case
      if(idx>=n || start>end) return NULL;
      int ele=pre[idx++];
      Node* root=new Node(ele);
      int pos=mp[ele];   // to find the element in inorder using this index
     
      
      root->left=solve(in,pre,idx,start,pos-1,n,mp);
      root->right=solve(in,pre,idx,pos+1,end,n,mp);
     
      return root;
  }
  
  
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &in, vector<int> &pre) {
        int n=in.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
        int preidx=0;
        Node* ans=solve(in,pre,preidx,0,n-1,n,mp);
        return ans;
    }
};