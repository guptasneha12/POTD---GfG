class Trie {
  public:
  
  bool end;
  vector<Trie*> child;

    Trie() {
        // implement Trie
        end=false;
        child.resize(26,NULL);
    }

    void insert(string &word) {
        // insert word into Trie
        Trie* root=this;
        for(auto &it:word){
            int idx=it-'a';
            if(!root->child[idx]){
                root->child[idx]=new Trie();
            }
            root=root->child[idx];
        }
        root->end=true;
    }



    bool search(string &word) {
        // search word in the Trie
        Trie* root=this;
        for(auto &it:word){
            int idx=it-'a';
            if(!root->child[idx]){
               return false;
            }
            root=root->child[idx];
        }
        return root->end;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Trie* root=this;
        for(auto &it:word){
            int idx=it-'a';
            if(!root->child[idx]){
                return false;
            }
            root=root->child[idx];
        }
        return true;
    }
};