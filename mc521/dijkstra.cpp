#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

int dijkstra (vector<vector<int>> &graph, vector<vector<int>> &w, int source, int destination) {
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


    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int v, k;
        cin >> v >> k;
        vector<vector<int>> graph(v, vector<int>());
        vector<vector<int>> weights(v, vector<int>(v, -1));
        for (int j = 0; j < k; j++) { //loop that creates graph and weights matrix
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            // cout << a << ' ' << b << '\n';
            graph[a].push_back(b);
            // graph[b].push_back(a);
            weights[a][b] = c;
            // weights[b][a] = c;
        }
        int source, dest;
        cin >> source >> dest;
        source--;
        dest--;
        // cout << dijkstra(graph, weights, source, dest) << '\n';
        int dist = dijkstra(graph, weights, source, dest);
        if (dist < INF) {
            cout << dist << '\n';
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
