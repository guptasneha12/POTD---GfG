class Node{
    public:
    int data;
    int idx;
    Node* left;
    Node* right;
    Node(int data,int idx){
        this->data=data;
        this->idx=idx;
        this->left = NULL;
        this->right = NULL;
    }
};

// for compariosn of equal data value
class compare{
    public:
    bool operator()(Node* a, Node* b){
        if(a->data == b->data) return a->idx > b->idx;
        return a->data > b->data;
    }
    
};


class Solution {
  public:
  
  // to print answer in preorder
  void solve(Node* root, string s, vector<string> &ans){
      if(!root) return;
      // leaf node
      if(!root->left && !root->right){
          if(s==""){
              s="0";
          }
          ans.push_back(s);
          return;
      }
      solve(root->left,s+'0',ans);
      solve(root->right,s+'1',ans);
  }
  
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // Code here
        priority_queue<Node*,vector<Node*>,compare> minheap;
        for(int i=0;i<f.size();i++){
            minheap.push(new Node(f[i],i));
        }
        while(minheap.size()>1){
            Node* left=minheap.top();
            minheap.pop();
            Node* right=minheap.top();
            minheap.pop();
            Node* node=new Node(left->data+right->data,min(left->idx,right->idx));
            node->left=left;
            node->right=right;
            minheap.push(node);
        }
        // print answer
        Node* root=minheap.top();
        vector<string> ans;
        string str;
        solve(root,str,ans);
        return ans;
        
    }
};