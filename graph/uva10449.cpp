#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

bool bfs (vector<vector<int>> graph, int source, int destination) {
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    if (source == destination)
        return true;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                if (v == destination)
                return true;
                else
                q.push(v);
            }
        }
    }
    return false;
}

int bellman_ford (vector<vector<int>> graph, vector<vector<int>> weights, int source, int destination) {
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

    if (distance[destination] < 3)
        return -1;

    for (int j = 0; j < n; j++) {
        int size_j = graph[j].size();
        for (int k = 0; k < size_j; k++) {
            int u, v;
            u = j;
            v = graph[j][k];
            if (distance[v] > distance[u] + weights[u][v]) {
                if(bfs(graph, v, destination))
                    return -1;
            }
        }
    }

    if (!bfs(graph, 0, destination))
        return -1;
    return distance[destination];
}

int main() {
    int n;
    int set = 1;
    while (scanf("%d", &n) != EOF) {
        vector<int> busyness(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> busyness[i];
        }
        int m;
        cin >> m;
        vector<vector<int>> graph(n);
        vector<vector<int>> weights(n, vector<int>(n));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph[u].push_back(v);
            weights[u][v] = (busyness[v] - busyness[u])*(busyness[v] - busyness[u])*(busyness[v] - busyness[u]);
        }
        cout << "Set #" << set++ << '\n';
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int destination;
            cin >> destination;
            destination--;
            int result = bellman_ford(graph, weights, 0, destination);
            if (result < 3)
                cout << "?\n";
            else
                cout << result << '\n';
        }
    }

    return 0;
}
