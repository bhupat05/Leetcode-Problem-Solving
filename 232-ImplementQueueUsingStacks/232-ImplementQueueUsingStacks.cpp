// Last updated: 3/18/2026, 2:28:42 PM
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    // Push element x to the back of the queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from the front of the queue
    int pop() {
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // Pop the top element from s2
        int r = s2.top();
        s2.pop();
        return r;
    }

    // Get the front element of the queue
    int peek() {
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        // Return the top element from s2
        return s2.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

