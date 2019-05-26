#include <bits/stdc++.h>
#define INF 9999999

using namespace std;

int bfs (vector<vector<int>> graph, int source) {
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> distance(n, INF);
    int sum = 0;

    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                int aux;
                visited[v] = true;
                distance[v] = aux = distance[u] + 1;
                sum += aux;
                q.push(v);
            }
        }
    }
    return sum;
}

int main() {
    int have_you_ever_seen_the_rain = 1;
    int u, v;
    cin >> u >> v;
    while (u != 0 || v != 0) {
        vector<vector<int>> graph(100);
        vector<bool> presence(100);
        u--;
        v--;
        presence[u] = true;
        presence[v] = true;
        graph[u].push_back(v);
        int a, b;
        cin >> a >> b;
        while (a != 0 || b != 0) {
            a--;
            b--;
            presence[a] = true;
            presence[b] = true;
            graph[a].push_back(b);
            cin >> a >> b;
        }
        int sum = 0;
        int num_of_nodes = 0;
        for (int i = 0; i < 100; i++) {
            if (presence[i]) {
                sum += bfs(graph, i);
                num_of_nodes++;
            }
        }
        double res = (double) sum / (double) ((num_of_nodes*num_of_nodes) - num_of_nodes);
        printf("Case %d: average length between pages = %.3lf clicks\n", have_you_ever_seen_the_rain++, res);
        cin >> u >> v;
    }

    return 0;
}
