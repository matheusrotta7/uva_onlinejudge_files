#include <bits/stdc++.h>

using namespace std;
int counter;

bool bfs (vector<vector<int>> graph) {
    counter = 0;
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<int> color(n, -1); //-1 = not yet colored, 0 = white, 1 = black
    queue<int> q;
    for (int j = 0; j < n; j++) {
        if (!vis[j]) {
            int aux_counter = 0;
            int num_of_nodes = 0;
            num_of_nodes++;
            color[j] = 0;
            q.push(j);
            vis[j] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int i = 0; i < graph[cur].size(); i++) {
                    int aux = graph[cur][i];
                    if (!vis[aux]) {
                        num_of_nodes++;
                        vis[aux] = true;
                        color[aux] = (color[cur] == 1? 0:1);
                        if (color[aux] == 1)
                            aux_counter++;
                        q.push(aux);
                    }
                    else {
                        if (color[cur] == color[aux])
                            return false;
                    }
                }
            }
            aux_counter = min (aux_counter, num_of_nodes - aux_counter);
            if (aux_counter == 0) aux_counter = 1;
            counter += aux_counter;
        }
    }

    return true;

}

int main() {

    int n, m, l;
    cin >> l;

    for (int j = 0; j < l; j++) {
        cin >> n >> m;
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool bicolorable = bfs(graph);
        // counter = min (counter, n-counter);
        if (bicolorable)
            cout << counter << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}
