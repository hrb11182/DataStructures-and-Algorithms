/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

/*
 Here we are going to have two stacks one will store the elements and the next will store the min elements if we push the element in stack we compare it with the top element of the min stack if it is smaller then that then we will push that element in both the stack else we push the given value in our stack and we push the present top value of min stack again in the mion stack so that number of elements in both the stack remain constant and the minimum element remain on the top of the min stack so when ever it asks for min element we pop out the first element of our mins stack this will contain the min element for each index.
*/


class MinStack {
    int stack[10000];
    int min[10000];
    int topPtr;
    int minPtr;
public:
    /** initialize your data structure here. */
    MinStack() {
        topPtr = -1;
        minPtr = -1;
    }
    
    void push(int x) {
        if(topPtr >= 10000)
            return;
        
        stack[++topPtr] = x;
        
        if(minPtr >= 0)
        {
            if(min[minPtr] > x)
                min[++minPtr] = x;
            else
            {
                min[minPtr+1] = min[minPtr];
                minPtr += 1;
            }
        }
        else
            min[++minPtr] = x;
                
    }
    
    void pop() {
        if(topPtr < 0)      //Underflow
            return;
        
        topPtr -= 1;
        minPtr -= 1;
    }
    
    int top() {        
        return stack[topPtr];
    }
    
    int getMin() {
        return min[minPtr];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
public:
    
    /*4, 6, 3, 2
    (4, 4)
    (6, 4)
    (3, 3)
    (2, 2)*/
    
    stack<pair<int,int>> s;
        
    /** initialize your data structure here. */
    MinStack() {
        //while(!s.empty()) {
         //   s.clear();
            
    }
    
    void push(int x) {
        if(s.empty()) {
            s.push({x, x});
        }
        else {
            s.push({x, min(x, s.top().second)});
        }
    }
    
    void pop() {
        if(!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */