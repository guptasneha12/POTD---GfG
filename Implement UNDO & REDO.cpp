class Solution {
    private: 
    string doc;
    stack<char> st; // stores undo elements
  public:
    void append(char x) {
        // append x into document
        doc.push_back(x);
        while(!st.empty()) st.pop();
    }

    void undo() {
        // undo last change
        if(!doc.empty()){
            st.push(doc.back());
            doc.pop_back();
        }
    }

    void redo() {
        // redo changes
        if(!st.empty()){
            doc.push_back(st.top());
            st.pop();
        }
    }

    string read() {
        // read the document
        return doc;
    }
};