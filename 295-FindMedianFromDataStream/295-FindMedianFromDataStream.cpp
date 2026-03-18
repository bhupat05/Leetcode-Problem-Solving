// Last updated: 3/18/2026, 2:28:15 PM
class MedianFinder {
private:
    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right; 

public:
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};
