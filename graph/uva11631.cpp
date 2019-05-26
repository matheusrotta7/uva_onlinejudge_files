#include <bits/stdc++.h>

using namespace std;

int parent[200001];
int rank_[200001];

typedef struct edge {
    int u;
    int v;
    int w;
} edge;

void make_set (int x) {
    parent[x] = x;
    rank_[x] = 0;
}

int find_set (int x) {
    if (x != parent[x])
        parent[x] = find_set (parent[x]);
    return parent[x];
}

void link (int x, int y) {
    if (rank_[x] > rank_[y])
        parent[y] = x;
    else
        parent[x] = y;
        if (rank_[x] == rank_[y])
            rank_[y]++;
}

void unite (int x, int y) {
    link(find_set(x), find_set(y));
}

bool comp (edge a, edge b) {
    return a.w < b.w;
}

int mst_kruskal(vector<edge> graph, int m, int n) {
    int used_weights = 0;
    for (int i = 0; i < m; i++) {
        make_set(i);
    }
    sort(graph.begin(), graph.end(), comp);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        if (find_set(u) != find_set(v)) {
            used_weights += w;
            unite(u, v);
        }
    }
    return used_weights;
}

int main() {

    int m, n;
    cin >> m >> n;
    while (m != 0 && n != 0) {
        for (int i = 0; i < m; i++) {
            parent[i] = -1;
            rank_[i] = -1;
        }
        vector<edge> graph;
        long int total_weights = 0;
        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edge e;
            e.u = u;
            e.v = v;
            e.w = w;
            total_weights += w;
            graph.push_back(e);
        }
        cout << total_weights - mst_kruskal(graph, m, n) << '\n';

        cin >> m >> n;
    }
    return 0;
}
