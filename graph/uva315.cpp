#include <bits/stdc++.h>

using namespace std;

void dfs_visit (int i, vector<vector<int>> graph, vector<bool> &visited, vector<int> &parent, vector<int> &disc, vector<int> &low, int &time_, vector<bool> &ap) {
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
                 ap[i] = true;

              // (2) If u is not root and low value of one of its children is more
              // than discovery value of u.
              if (parent[i] != -1 && low[cur] >= disc[i])
                 ap[i] = true;
         }
         else if (cur != parent[i]) {
             low[i] = min(low[i], disc[cur]);
         }
     }
}

void dfs (vector<vector<int>> graph, vector<bool> &ap) {
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


int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<vector<int>> graph(n);
        int u;
        cin >> u;
        while (u != 0) {
            u--;
            string s;
            getline(cin, s);
            stringstream ss(s);
            int v;
            while (ss >> v) {
                v--;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            cin >> u;
        }
        vector<bool> ap(n, false);
        dfs(graph, ap);
        int count = 0;
        for (int i = 0; i < ap.size(); i++) {
            if (ap[i])
                count++;
        }
        cout  << count << '\n';
        cin >> n;
    }

    return 0;
}
