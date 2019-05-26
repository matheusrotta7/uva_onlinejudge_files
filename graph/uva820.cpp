#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

// typedef struct intel {
//     bool has_path;
//     int min_cap;
//     vector<pair<int,int>> edges;
// } intel;

bool bfs (vector<vector<int>> graph, vector<vector<int>> &weights, vector<vector<int>> &flux, int source, int destination) {
    bool has_path = false;
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> predec(n, -1);
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];

            if (!visited[v] && weights[u][v] != 0) {
                visited[v] = true;
                predec[v] = u;
                if (v == destination) {
                    has_path = true;
                    break;
                }
                q.push(v);
            }
        }
    }

    if (has_path) {
        int cur = destination;
        int min_ = INF;
        while (predec[cur] != -1) {
            min_ = min(min_, weights[predec[cur]][cur]);
            cur = predec[cur];
        }
        cur = destination;
        while (predec[cur] != -1) {
            weights[predec[cur]][cur] -= min_;
            weights[cur][predec[cur]] += min_;
            flux[predec[cur]][cur] += min_;
            flux[cur][predec[cur]] = -flux[predec[cur]][cur];
            cur = predec[cur];
        }
    }
    return has_path;
}

int edmonds_karp (vector<vector<int>> graph, vector<vector<int>> weights, vector<vector<int>> &flux, int s, int t) {
    while (bfs(graph, weights, flux, s, t));
    int sum = 0;
    for (int i = 0; i < graph[s].size(); i++) {
        int v = graph[s][i];
        sum += flux[s][v];
    }
    return sum;
}

int main() {
    int naruto = 1;
    int n;
    cin >> n;
    while (n != 0) {
        // if (naruto != 1) cout << '\n';
        vector<vector<int>> graph(n);
        vector<vector<int>> weights(n, vector<int>(n, 0));
        vector<vector<int>> flux(n, vector<int>(n, 0));
        vector<vector<bool>> edge_exists(n, vector<bool>(n, false));
        int s, t, c;
        cin >> s >> t >> c;
        s--;
        t--;
        for (int i = 0; i < c; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            if (!edge_exists[u][v]) {
                graph[u].push_back(v);
                graph[v].push_back(u);
                weights[u][v] = w;
                weights[v][u] = w;
                edge_exists[u][v] = true;
                edge_exists[v][u] = true;
            }
            else {
                weights[u][v] += w;
                weights[v][u] += w;
            }
        }
        cout << "Network " << naruto++ << '\n';
        cout << "The bandwidth is " << edmonds_karp (graph, weights, flux, s, t) << ".\n\n";
        cin >> n;
    }

    return 0;
}
