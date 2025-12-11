#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    int n = 5; // number of stops (nodes)
    vector<vector<Edge>> graph(n);

    // add some sample roads (u -> v with time cost)
    auto add_edge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected road
    };

    add_edge(0, 1, 4);
    add_edge(0, 2, 1);
    add_edge(2, 1, 2);
    add_edge(1, 3, 1);
    add_edge(2, 3, 5);
    add_edge(3, 4, 3);

    int source = 0; // e.g., main residential bus stand

    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[source] = 0;

    // min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto &e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source stop " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Stop " << i << ": " << dist[i] << "\n";
    }
    return 0;
}
