// Last updated: 3/18/2026, 2:26:19 PM
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int &num : nums) {
            pq.push(num);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top(); // return Kth largest
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
