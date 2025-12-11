#include <bits/stdc++.h>
using namespace std;

struct Ambulance {
    int id;
    int distance; // distance from accident
};

int main() {
    // Using (distance, id) in min-heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Sample data: (distance, ambulance_id)
    pq.push({5, 101});
    pq.push({2, 102});
    pq.push({8, 103});
    pq.push({3, 104});

    auto nearest = pq.top();
    cout << "Send ambulance ID " << nearest.second
         << " with distance " << nearest.first << "\n";

    return 0;
}
