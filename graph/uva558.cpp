#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

bool bellman_ford (vector<vector<int>> graph, vector<vector<int>> weights, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[source] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < n; j++) {
            int size_j = graph[j].size();
            for (int k = 0; k < size_j; k++) {
                int u, v;
                u = j;
                v = graph[j][k];
                if (distance[v] > distance[u] + weights[u][v]) {
                    distance[v] = distance[u] + weights[u][v];
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        int size_j = graph[j].size();
        for (int k = 0; k < size_j; k++) {
            int u, v;
            u = j;
            v = graph[j][k];
            if (distance[v] > distance[u] + weights[u][v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);
        vector<vector<int>> weights(n, vector<int>(n));
        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            weights[u][v] = w;
        }
        int source = 0;
        bool possible = !bellman_ford(graph, weights, source);
        if (possible)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }

    return 0;
}
