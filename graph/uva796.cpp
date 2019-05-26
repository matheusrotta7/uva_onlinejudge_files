#include <bits/stdc++.h>

using namespace std;

typedef struct link {
    int a;
    int b;
} link;

void dfs_visit (int i, vector<vector<int>> graph, vector<bool> &visited, vector<int> &parent, vector<int> &disc, vector<int> &low, int &time_, vector<link> &clinks) {
     visited[i] = true;
     disc[i] = low[i] = ++time_;
     for (int j = 0; j < graph[i].size(); j++) {
         int cur = graph[i][j];
         if (!visited[cur]) {
             parent[cur] = i;
             dfs_visit(cur, graph, visited, parent, disc, low, time_, clinks);
             low[i] = min(low[i], low[cur]);
             if (low[cur] > disc[i]) {
                 link newlink;
                 newlink.a = min(cur, i);
                 newlink.b = max(cur, i);
                 clinks.push_back(newlink);
             }
         }
         else if (cur != parent[i]) {
             low[i] = min(low[i], disc[cur]);
         }
     }
}

vector<link> dfs (vector<vector<int>> graph) {
    vector<link> clinks;
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int time_ = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_visit(i, graph, visited, parent, disc, low, time_, clinks);
        }
    }
    return clinks;
}

bool comp (link m, link n) {
    if (m.a < n.a)
        return true;
    else if (m.a > n.a)
        return false;
    else
        return m.b < n.b;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            cout << "0 critical links\n\n";
            continue;
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            int cur, deg;
            scanf("%d (%d)", &cur, &deg);
            for (int i = 0; i < deg; i++) {
                int v;
                cin >> v;
                graph[cur].push_back(v);
            }

        }
        vector<link> clinks = dfs (graph);
        cout << clinks.size() << " critical links\n";
        sort(clinks.begin(), clinks.end(), comp);
        for (int i = 0; i < clinks.size(); i++) {
            cout << clinks[i].a << " - " << clinks[i].b << "\n";
        }
        cout << '\n';
    }

    return 0;
}
