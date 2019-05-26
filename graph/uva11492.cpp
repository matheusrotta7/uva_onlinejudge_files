#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

int dijkstra (vector<vector<int>> graph, vector<vector<int>> w, int source, int n, int k) {
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
    int min_ = INF;
    for (int i = 0; i < n; i++) {
        int cur = (n+1)*k + i + 1;
        min_ = min(min_, distance[cur]);
    }
    return min_;
}


int main() {

    int m;
    cin >> m;
    while (m != 0) {

        string source, dest;
        cin >> source >> dest;
        vector<vector<int>> graph;
        unordered_map<string, int> word_to_int;
        for (int i = 0; i < m; i++) {
            string lang1, lang2, word;
            cin >> lang1 >> lang2 >> word;
        }

        cin >> m;
    }

    return 0;
}
