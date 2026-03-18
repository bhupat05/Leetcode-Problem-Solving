// Last updated: 3/18/2026, 2:19:54 PM
class SegmentTree {
public:
    int n;
    vector<int> minv, maxv, lazy;

    SegmentTree(vector<int>& a) {
        n = a.size();
        minv.resize(4 * n);
        maxv.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if (l == r) {
            minv[node] = maxv[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);
        pull(node);
    }

    void pull(int node) {
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
    }

    void apply(int node, int val) {
        minv[node] += val;
        maxv[node] += val;
        lazy[node] += val;
    }

    void push(int node) {
        if (lazy[node] != 0) {
            apply(node * 2, lazy[node]);
            apply(node * 2 + 1, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }

        push(node);
        int mid = (l + r) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr, val);
        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr, val);

        pull(node);
    }

    int findLast(int node, int l, int r, int start) {
        if (r < start || minv[node] > 0 || maxv[node] < 0)
            return -1;

        if (l == r)
            return l;

        push(node);
        int mid = (l + r) / 2;

        int res = -1;
        if (start <= r)
            res = findLast(node * 2 + 1, mid + 1, r, start);
        if (res != -1)
            return res;

        return findLast(node * 2, l, mid, start);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        map<int, queue<int>> occ;

        auto sign = [&](int x) {
            if (x % 2 == 0) return 1;
            return -1;
        };

        vector<int> prefix(n);
        prefix[0] = sign(nums[0]);
        occ[nums[0]].push(0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (occ[nums[i]].empty())
                prefix[i] += sign(nums[i]);
            occ[nums[i]].push(i);
        }

        SegmentTree seg(prefix);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int pos = seg.findLast(1, 0, n - 1, i + ans);
            if (pos != -1)
                ans = max(ans, pos - i + 1);

            occ[nums[i]].pop();

            int next_pos = n;
            if (!occ[nums[i]].empty())
                next_pos = occ[nums[i]].front();

            seg.update(1, 0, n - 1, i, next_pos - 1, -sign(nums[i]));
        }

        return ans;
    }
};
