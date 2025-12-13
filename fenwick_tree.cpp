#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    int n;
    vector<float> bit;
    FenwickTree(int n_) : n(n_), bit(n_ + 1, 0.0f) {}
    void update(int idx, float delta) {
        for (int i = idx + 1; i <= n; i += i & -i) bit[i] += delta;
    }
    float query(int idx) const {
        float res = 0.0f;
        for (int i = idx + 1; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
};

int main() {
    vector<float> distances = {31.87, 20.6, 34.1, 15.3};
    FenwickTree ft((int)distances.size());
    for (int i = 0; i < (int)distances.size(); i++) ft.update(i, distances[i]);
    cout << "Cumulative distance to 3rd city: " << ft.query(2) << " km\n";
    cout << "Total distance of all 4 cities: " << ft.query(3) << " km\n";
    return 0;
}
