#include <bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

typedef struct edge {
    int v;
    int w;
} edge;

int dijkstra (vector<vector<edge>> graph) {
    int source = 0;
    int destination = graph.size() - 1;
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
            edge e = graph[u][i];
            int v = e.v;
            if (distance[v] > distance[u] + e.w) {
                distance[v] = distance[u] + e.w;
                predecessor[v] = u;
                Q.push(pair<int,int>(distance[v], v));
            }
        }
    }
    return distance[destination];
}

int main() {

    int mazes;
    cin >> mazes;

    for (int i = 0; i < mazes; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> maze(n, vector<int>(m, -1));
        vector<vector<edge>> graph(n*m);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> maze[j][k];
            }
        }
        for (int j = 0; j < n-1; j++) {
            for (int k = 0; k < m-1; k++) {
                int index = j*m + k;
                edge right, down;
                right.w = maze[j][k+1];
                right.v = index + 1;
                down.w = maze[j+1][k];
                down.v = index + m;
                edge left;
                left.v = index;
                left.w = maze[j][k];

                graph[index].push_back(right);
                graph[index].push_back(down);
                graph[right.v].push_back(left);
                graph[down.v].push_back(left); //up is the same as left
            }
        }
        for (int k = 0; k < m-1; k++) {
            int index = (n-1)*m + k;
            edge right;
            right.w = maze[n-1][k+1];
            right.v = index + 1;
            edge left;
            left.v = index;
            left.w = maze[n-1][k];

            graph[index].push_back(right);
            graph[right.v].push_back(left);
        }
        for (int j = 0; j < n-1; j++) {
            int index = j*m + m-1;
            edge down;
            down.w = maze[j+1][m-1];
            down.v = index + m;
            edge up;
            up.v = index;
            up.w = maze[j][m-1];

            graph[index].push_back(down);
            graph[down.v].push_back(up);
        }
        cout << dijkstra(graph) + maze[0][0] << '\n';
    }

    return 0;
}
