#include <bits/stdc++.h>

using namespace std;

bool bfs (vector<vector<int>> graph) {
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<int> color(n, -1); //-1 = not yet colored, 0 = white, 1 = black
    queue<int> q;
    color[0] = 0;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int aux = graph[cur][i];
            if (!vis[aux]) {
                vis[aux] = true;
                color[aux] = (color[cur] == 1? 0:1);
                q.push(aux);
            }
            else {
                if (color[cur] == color[aux])
                    return false;
            }
        }
    }
    return true;

}

int main() {

    int n, m;
    cin >> n;

    while (n != 0) {
        cin >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool bicolorable = bfs(graph);
        if (bicolorable)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
        cin >> n;
    }

    return 0;
}
