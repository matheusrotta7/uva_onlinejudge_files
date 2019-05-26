#include <bits/stdc++.h>
#include <stdio.h>

#define INF 1000000000
#define NIL -1

using namespace std;

int dijkstra (vector<vector<int>> &graph, vector<map<int,int>> &w, int source, int destination) {
    // int source = 0;
    // int destination = graph.size() - 1;
    int num_vertexes = graph.size();

    vector<int> distance(num_vertexes, INF);
    vector<int> predecessor(num_vertexes, NIL);
    distance[source] = 0;

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    // for (int i = 0; i < num_vertexes; i++) {
    Q.push(pair<int,int>(distance[source], source));
    // }
    while(!Q.empty()) {
        int d = Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if (d > distance[u])
            continue;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (distance[v] > distance[u] + w[u][v]) {
                distance[v] = distance[u] + w[u][v];
                predecessor[v] = u;
                Q.push(pair<int,int>(distance[v], v));
            }
        }
    }
    int cur;
    vector<int> path;
    cur = destination;
    while (cur != source) {
        path.push_back(cur);
        cur = predecessor[cur];
    }
    path.push_back(cur);
    int s = path.size();
    for (int i = s-1; i >= 0; i--) {
        cout << path[i]+1 << ' ';
    }
    return distance[destination];
}


int main() {


    int test_cases = 1;
    // cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int v, k, source, dest;
        cin >> v >> k;

        vector<vector<int>> graph(v, vector<int>());
        vector<map<int,int>> weights(v);
        for (int j = 0; j < k; j++) { //loop that creates graph and weights matrix
            int a, b, c;
            // cin >> a >> b >> c;
            scanf("%d %d %d\n", &a, &b, &c);
            a--;
            b--;
            // cout << a << ' ' << b << '\n';
            graph[a].push_back(b);
            graph[b].push_back(a);
            weights[a][b] = c;
            weights[b][a] = c;
        }

        // cout << dijkstra(graph, weights, source, dest) << '\n';
        int dist = dijkstra(graph, weights, 0, v-1);
        // if (dist < INF) {
        //     cout << dist << '\n';
        // }
        // else {
        //     cout << "-1\n";
        // }
    }

    return 0;
}
