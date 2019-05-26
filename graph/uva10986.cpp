#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

int dijkstra (vector<vector<int>> graph, vector<vector<int>> w, int source, int destination) {
    // int source = 0;
    // int destination = graph.size() - 1;
    int num_vertexes = graph.size();

    vector<int> distance(num_vertexes, INF);
    vector<int> predecessor(num_vertexes, NIL);
    distance[source] = 0;

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    for (int i = 0; i < num_vertexes; i++) {
        Q.push(pair<int,int>(distance[i], i));
    }
    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (distance[v] > distance[u] + w[u][v]) {
                distance[v] = distance[u] + w[u][v];
                predecessor[v] = u;
                Q.push(pair<int,int>(distance[v], v));
            }
        }
    }
    return distance[destination];
}

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<int>> graph(n);
        vector<vector<int>> w(n, vector<int>(n, INF));
        for (int j = 0; j < m; j++) {
            int u, v, w_;
            cin >> u >> v >> w_;
            graph[u].push_back(v);
            graph[v].push_back(u);
            w[u][v] = min(w_, w[u][v]);
            w[v][u] = min(w_, w[v][u]);
        }
        int latency = dijkstra(graph, w, s, t);
        cout << "Case #" << i+1 << ": ";
        if (latency == INF)
            cout << "unreachable" << '\n';
        else
            cout << latency << '\n';
    }

    return 0;
}
