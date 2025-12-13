#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
public:
    SparseTable(const vector<float>& arr) : n(arr.size()) {
        int K = 1;
        while ((1 << K) <= n) K++;
        st.assign(K, vector<float>(n));
        for (int i = 0; i < n; i++) st[0][i] = arr[i];
        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    float query(int L, int R) const {
        int len = R - L + 1;
        int k = 31 - __builtin_clz(len);
        return min(st[k][L], st[k][R - (1 << k) + 1]);
    }
private:
    int n;
    vector<vector<float>> st;
};

int main() {
    vector<float> distances = {31.87, 52.47, 34.1, 25.5, 40.2};
    SparseTable st(distances);
    cout << "Minimum distance between positions 0-2: " << st.query(0, 2) << " km\n";
    cout << "Minimum distance between positions 1-4: " << st.query(1, 4) << " km\n";
    return 0;
}
