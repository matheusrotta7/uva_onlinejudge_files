#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

vector<int> bfs (vector<vector<int>> graph, int source) {
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> distance(n, INF);

    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    return distance;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n);

        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s, d;
        cin >> s >> d;
        vector<int> dist_source = bfs(graph, s);
        vector<int> dist_dest = bfs(graph, d);
        int cur_max = -INF;
        for (int j = 0; j < n; j++) {
            cur_max = max(cur_max, dist_source[j] + dist_dest[j]);
        }
        cout << "Case " << i + 1 << ": " << cur_max << '\n';
    }

    return 0;
}
