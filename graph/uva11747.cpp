#include <bits/stdc++.h>

using namespace std;

int parent[101];
int rank_[101];

typedef struct edge {
    int u;
    int v;
    int w;
} edge;

typedef struct node {
    int v;
    int w;
} node;

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

void mst_kruskal(vector<vector<node>> &graph, vector<edge> edges, int n, int m) {

    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if (find_set(u) != find_set(v)) {
            node p, q;
            p.v = v;
            p.w = w;
            q.v = u;
            q.w = w;
            graph[u].push_back(p);
            graph[v].push_back(q);
            unite(u, v);
        }
    }
}

void bfs (vector<vector<node>> graph, int source , int dest) {
    vector<bool> cor(graph.size(), false);
    node sample;
    sample.v = -1;
    sample.w = 0;
    vector<node> pi (graph.size(), sample);
    cor[source] = true;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v;
            int w = graph[u][i].w;
            if (cor[v] == false) {
                cor[v] = true;
                pi[v].v = u;
                pi[v].w = w;
                if (v == dest) goto label;
                q.push(v);
            }
        }
    }
    label:
    int a, b;
    a = dest;
    int minimum = -100000;
    while (true) {
        b = pi[a].v;
        if (minimum < pi[a].w)
            minimum = pi[a].w;
        if (b == source) {
            cout << minimum << '\n';
            break;
        }
        if (b == -1) {
            cout << "no path\n";
            break;
        }
        a = b;
    }

}

int main() {

    int c, s, q;
    cin >> c >> s >> q;
    int bingo = 1;
    while (c != 0 || s != 0 || q != 0) {
        if (bingo != 1)
            cout << '\n';
        for (int i = 0; i < c; i++) {
            parent[i] = -1;
            rank_[i] = -1;
        }
        vector<edge> edges;
        vector<vector<node>> graph(c);
        for (int i = 0; i < s; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            edge e;
            e.u = u;
            e.v = v;
            e.w = w;
            edges.push_back(e);
        }
        mst_kruskal(graph, edges, c, s);
        cout << "Case #" << bingo++ << '\n';
        for (int i = 0; i < q; i++) {
            int source, dest;
            cin >> source >> dest;
            source--;
            dest--;
            bfs(graph, source, dest);
        }
        cin >> c >> s >> q;
    }
    return 0;
}
