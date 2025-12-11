#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int> &arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr)
             + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, val);
        else update(2 * node + 1, mid + 1, r, pos, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
};

int main() {
    // hourly usage for 6 hours
    vector<int> usage = {2, 3, 5, 1, 4, 6};
    SegmentTree st(usage);

    // total usage from hour 1 to 4 (0-based index)
    cout << "Sum [1,4] = " << st.query(1, 0, usage.size()-1, 1, 4) << "\n";

    // update hour 2 usage to 10
    st.update(1, 0, usage.size()-1, 2, 10);
    cout << "After update, Sum [1,4] = " 
         << st.query(1, 0, usage.size()-1, 1, 4) << "\n";

    return 0;
}
