#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 6; // rooms
    vector<vector<int>> graph(n);

    auto add_edge = [&](int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    };

    // Simple building layout
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(2, 5); // room 5 is exit

    int startRoom = 0;  // starting room
    int exitRoom  = 5;  // exit

    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;

    dist[startRoom] = 0;
    q.push(startRoom);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == exitRoom) break;
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[exitRoom] == -1) {
        cout << "No path to exit.\n";
    } else {
        cout << "Shortest steps to exit: " << dist[exitRoom] << "\nPath: ";
        vector<int> path;
        for (int v = exitRoom; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
