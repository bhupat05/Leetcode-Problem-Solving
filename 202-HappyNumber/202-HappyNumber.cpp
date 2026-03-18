// Last updated: 3/18/2026, 2:29:14 PM
class Solution {
public:
    int getNext(int n) {
        int val = 0;
        while (n) {
            int d = n % 10;
            val += d * d;
            n /= 10;
        }
        return val;
    }

    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
