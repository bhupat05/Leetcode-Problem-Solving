// Last updated: 3/18/2026, 2:22:45 PM
class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> addedBack;

    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if(!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            addedBack.erase(smallest);    
            return smallest;
        }
        return current++;
    }
    
    void addBack(int num) {
        
        if(num < current && !addedBack.count(num)) {
            minHeap.push(num);
            addedBack.insert(num);
        }
    }
};
