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

    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        vector<int> T(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> T[i];
        }
        vector<vector<int>> graph(100*(n+1));
        vector<vector<int>> weights(100*(n+1), vector<int>(100*(n+1)));
        string dummy;
        getline(cin, dummy);
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            int fl;
            vector<int> visited_floors;
            while (ss >> fl) {
                // int cur = (n+1)*k + i + 1;
                visited_floors.push_back(fl);
            }
            int size = visited_floors.size();
            for (int j = 0; j < size; j++) {
                int cur_floor = visited_floors[j];
                int u = (n+1)*cur_floor + i + 1;
                int aux = (n+1)*cur_floor;
                graph[u].push_back(aux);
                graph[aux].push_back(u);
                weights[u][aux] = weights[aux][u] = cur_floor == 0? 0 : 30; //30s + 30s = 60s to change floors, which is done via aux vertex
                for (int l = j + 1; l < size; l++) {
                    int dest_floor = visited_floors[l];
                    int v = (n+1)*dest_floor + i + 1;
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                    weights[u][v] = weights[v][u] = (dest_floor - cur_floor)*T[i];
                }

            }
        }
        int min_time = dijkstra (graph, weights, 0, n, k);
        if (min_time == INF)
            cout << "IMPOSSIBLE\n";
        else
            cout << min_time << '\n';
    }

    return 0;
}
