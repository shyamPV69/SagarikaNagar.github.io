#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(const vector<vector<int>>& graph, int start) {
    int n = (int)graph.size();
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cout << "Visited: " << u << "\n";
        for (int v : graph[u]) if (!visited[v]) st.push(v);
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0},
        {1}
    };
    dfs(graph, 0);
    return 0;
}
