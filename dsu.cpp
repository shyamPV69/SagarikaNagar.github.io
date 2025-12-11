#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

int main() {
    int n = 5; // pipeline junctions
    DSU dsu(n);

    // Connect some junctions (pipes)
    dsu.union_set(0, 1);
    dsu.union_set(1, 2);
    dsu.union_set(3, 4);

    // Check if junction 0 and 2 are connected
    if (dsu.find_set(0) == dsu.find_set(2))
        cout << "Junction 0 and 2 are in same water component.\n";
    else
        cout << "Junction 0 and 2 are NOT connected.\n";

    // 0 and 3?
    if (dsu.find_set(0) == dsu.find_set(3))
        cout << "Junction 0 and 3 are in same water component.\n";
    else
        cout << "Junction 0 and 3 are NOT connected.\n";

    return 0;
}
