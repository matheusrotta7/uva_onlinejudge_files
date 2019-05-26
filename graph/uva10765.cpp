#include <bits/stdc++.h>

using namespace std;

// void dfs_visit (int i, vector<vector<int>> graph, vector<bool> &visited) {
//      visited[i] = true;
//      for (int j = 0; j < graph[i].size(); j++) {
//          int cur = graph[i][j];
//          if (!visited[cur]) {
//              dfs_visit(cur, graph, visited);
//          }
//      }
// }

typedef struct node {
    int station;
    int pv;
} node;

// vector<vector<int>> remove(int out, vector<vector<int>> graph) {
//     int n = graph.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < graph[i].size(); j++) {
//             if (graph[i][j] == out) graph[i].erase(graph[i].begin()+j);
//         }
//     }
//     graph[out].clear();
//     //we did not really remove, just isolated the vertex, so we will
//     //have to decrease one value when storing pigeon value
//     return graph;
// }

// int dfs (vector<vector<int>> graph) {
//     int components = 0;
//     int n = graph.size();
//     vector<bool> visited(n, false);
//     // vector<bool> ap(n, false);
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             components++;
//             dfs_visit(i, graph, visited);
//         }
//     }
//     return components;
// }

void dfs_visit (int i, vector<vector<int>> graph, vector<bool> &visited, vector<int> &parent, vector<int> &disc, vector<int> &low, int &time_, vector<int> &ap) {
     visited[i] = true;
     int children = 0;
     disc[i] = low[i] = ++time_;
     for (int j = 0; j < graph[i].size(); j++) {
         int cur = graph[i][j];
         if (!visited[cur]) {
             children++;
             parent[cur] = i;
             dfs_visit(cur, graph, visited, parent, disc, low, time_, ap);
             low[i] = min(low[i], low[cur]);
              // (1) u is root of DFS tree and has two or more children.
              if (parent[i] == -1 && children > 1)
                 ap[i]++;

              // (2) If u is not root and low value of one of its children is more
              // than discovery value of u.
              if (parent[i] != -1 && low[cur] >= disc[i])
                 ap[i]++;
         }
         else if (cur != parent[i]) {
             low[i] = min(low[i], disc[cur]);
         }
     }
}

void dfs (vector<vector<int>> graph, vector<int> &ap) {
    int n = graph.size();
    vector<bool> visited(n, false);
    // vector<bool> ap(n, false);
    vector<int> parent(n, -1);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int time_ = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_visit(i, graph, visited, parent, disc, low, time_, ap);
        }
    }
    // return ap;
}

bool comp (node a, node b) {
    if (a.pv != b.pv)
        return a.pv > b.pv;
    else
        return a.station < b.station;
}


int main() {

    int n, m;
    cin >> n >> m;

    while (n != 0 || m != 0) {
        vector<vector<int>> graph(n);
        int u, v;
        cin >> u >> v;
        while (u != -1 || v != -1) {
            graph[u].push_back(v);
            graph[v].push_back(u);
            cin >> u >> v;
        }

        vector<node> pigeon_value;
        // for (int i = 0; i < n; i++) {
        //     node cur;
        //     cur.station = i;
        //     cur.pv =  dfs(remove(i, graph)) - 1;
        //     pigeon_value.push_back(cur);
        // }
        vector<int> ap(n, 0);
        dfs(graph, ap);
        for (int i = 0; i < n; i++) {
            node cur;
            cur.station = i;
            cur.pv =  ap[i]+1;
            pigeon_value.push_back(cur);
        }
        sort(pigeon_value.begin(), pigeon_value.end(), comp);
        for (int i = 0; i < m; i++) {
            cout << pigeon_value[i].station << ' ' << pigeon_value[i].pv << '\n';
        }
        cout << '\n';
        cin >> n >> m;
    }

    return 0;
}
