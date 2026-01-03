class Solution {
  public:
   // for merging linked list
   Node* mergeLL(Node* h1, Node* h2){
       Node* temp= new Node(0);
       Node* res=temp;
       while(h1!=NULL && h2!=NULL){
           if(h1->data < h2->data){
               temp->bottom=h1;
               temp=temp->bottom;
               h1=h1->bottom;
           }
           else{
               temp->bottom=h2;
               temp=temp->bottom;
               h2=h2->bottom;
           }
       }
       if(h1) temp->bottom=h1;
       else temp->bottom=h2;
       return res->bottom; // head of flatten ll
   }
  
    Node *flatten(Node *root) {
        // code here
        if(root==NULL) return NULL;
    // recursion 
    Node* head2 = flatten(root->next);
    return mergeLL(root,head2);
    }
};