#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

bool bfs (vector<vector<int>> graph, int source) {
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    if (source == n-1)
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
                if (v == n-1)
                return true;
                else
                q.push(v);
            }
        }
    }
    return false;
}

bool bellman_ford (vector<vector<int>> graph, vector<int> weights, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[source] = -100;

    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < n; j++) {
            int size_j = graph[j].size();
            for (int k = 0; k < size_j; k++) {
                int u, v;
                u = j;
                v = graph[j][k];
                if (distance[v] > distance[u] + weights[v]) {
                    distance[v] = distance[u] + weights[v];
                    if (distance[v] >= 0)
                        distance[v] = INF; //if player dies, desconsider this path (put INF again)
                }
            }
        }
    }
    bool aux = false;
    for (int j = 0; j < n; j++) {
        int size_j = graph[j].size();
        for (int k = 0; k < size_j; k++) {
            int u, v;
            u = j;
            v = graph[j][k];
            if (distance[v] > distance[u] + weights[v] && distance[v] != INF) {
                 aux = bfs(graph, v);
                 if (aux)
                    break;
            }
        }
    }
    // return true;
    return distance[n-1] < 0 || aux;
}


int main() {

    int n;
    cin >> n;
    while (n != -1) {
        vector<int> energy_values(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            int ev;
            cin >> ev;
            energy_values[i] = -ev;
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                v--;
                graph[i].push_back(v);
            }
        }
        bool winnable = bellman_ford(graph, energy_values, 0);
        // bool reachable = bfs(graph);
        if (winnable)
            cout << "winnable\n";
        else
            cout << "hopeless\n";

        cin >> n;
    }

    return 0;
}
