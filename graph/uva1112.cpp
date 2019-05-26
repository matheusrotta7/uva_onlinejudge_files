#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

int dijkstra (vector<vector<int>> graph, vector<vector<int>> w, int source, int t) {
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
    int num_of_mice = 0;
    for (int i = 0; i < num_vertexes; i++) {
        if (distance[i] <= t) num_of_mice++;
    }
    return num_of_mice;
}

int main() {

    int N;
    cin >> N;

    bool first = true;

    for (int i = 0; i < N; i++) {
        if (!first)
            cout << '\n';
        else
            first = false;
        int n, e, t, m;
        cin >> n >> e >> t >> m;
        vector<vector<int>> graph(n);
        vector<vector<int>> w(n, vector<int>(n, INF));
        for (int j = 0; j < m; j++) {
            int u, v, w_;
            cin >> u >> v >> w_;
            u--;
            v--;
            //transpose right here :)
            graph[v].push_back(u);

            w[v][u] = w_;

        }
        cout << dijkstra(graph, w, --e, t) << '\n';
    }

    return 0;
}
