class Solution {
    private:
    stack<int> s;
    int minEle;
  public:
    Solution() {
          minEle = -1;
    }
    
    // Add an element to the top of Stack
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        }

       
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }

        else {
            s.push(x);
        }
    }
    
    // Remove the top element from the Stack
    void pop() {
        if (s.empty()) {
            return ;
        }
        
        int top = s.top();
        s.pop();
        
 
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    // Returns top element of the Stack
    int peek() {
        if (s.empty()) {
            return -1;
        }

        int top = s.top();

     
        return (minEle > top) ? minEle : top;
    }
    
    // Finds minimum element of Stack
    int getMin() {
        if (s.empty())
            return -1;

        return minEle;
    }
};