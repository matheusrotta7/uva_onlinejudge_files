#include<bits/stdc++.h>

using namespace std;

bool bfs (vector<vector<int>> graph, int n, vector<int> colors) {
    int count = 0;
    bool bicolor = true;
    queue<int> q;
    vector<bool> visited(n, false);
    // vector<int> predec(n, -1);
    q.push(0);
    visited[0] = true;
    count++;
    colors[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        int cur_color = colors[u]; //should be 0 or 1
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (cur_color == 1) {
                if (colors[v] == -1) {
                    colors[v] = 0;
                }
                else if (colors[v] == 1) {
                    return false;
                }
            }

            if (cur_color == 0) {
                if (colors[v] == -1) {
                    colors[v] = 1;
                }
                else if (colors[v] == 0) {
                    return false;
                }
            }

            if (!visited[v]) {
                visited[v] = true;
                count++;
                // predec[v] = u;
                q.push(v);
            }
        }
    }

    return (count == n);

}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> colors(n, -1); //-1 means no color assigned

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool is_bicolorable = bfs (graph, n, colors);
    if (is_bicolorable)
        cout << "YES";
    else
        cout << "NO";


    return 0;
}
