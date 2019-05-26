#include <bits/stdc++.h>
#define INF 99999999;

using namespace std;

int parent[1001];
int rank_[1001];

int parent_s[1001];
int rank_s[1001];

typedef struct result {
    int best;
    int second_best;
} result;

typedef struct edge {
    int u;
    int v;
    double w;
} edge;

typedef struct point {
    int x;
    int y;
    int id;
} point;

void make_set_s (int x) {
    parent_s[x] = x;
    rank_s[x] = 0;
}

int find_set_s (int x) {
    if (x != parent_s[x])
        parent_s[x] = find_set_s (parent_s[x]);
    return parent_s[x];
}

void link_s (int x, int y) {
    if (rank_s[x] > rank_s[y])
        parent_s[y] = x;
    else
        parent_s[x] = y;
        if (rank_s[x] == rank_s[y])
            rank_s[y]++;
}

void unite_s (int x, int y) {
    link_s(find_set_s(x), find_set_s(y));
}


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

void copy (int n) {
    for (int i = 0; i < n; i++) {
        parent_s[i] = parent[i];
        rank_s[i] = rank_[i];
    }
}

int mst_kruskal_smart (vector<edge> graph, int n, int m, edge e) {

    for (int i = 0; i < n; i++) {
        make_set_s(i);
    }
    int counter = e.w;
    unite_s(e.u, e.v);
    sort(graph.begin(), graph.end(), comp);
    for (int i = 0; i < m; i++) {
        int u, v;
        double w;
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        if (find_set_s(u) != find_set_s(v)) {
            counter += w;
            unite_s(u, v);
        }

    }
    return counter;
}


result mst_kruskal(vector<edge> graph, int n, int m) {
    bool first = true;
    result r;
    r.second_best = INF;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    sort(graph.begin(), graph.end(), comp);
    for (int i = 0; i < m; i++) {
        int u, v;
        double w;
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        if (find_set(u) != find_set(v)) {
            counter += w;
            unite(u, v);
        }
        else {
            edge e = graph[i];
            r.second_best = min(r.second_best, mst_kruskal_smart(graph, n, m, e));
        }
    }
    r.best = counter;
    return r;
}

int main() {
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        vector<edge> graph;
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            parent[i] = -1;
            rank_[i] = -1;

            parent_s[i] = -1;
            rank_s[i] = -1;
        }

        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            edge e;
            e.u = u;
            e.v = v;
            e.w = w;
            graph.push_back(e);
        }
        result r;
        r = mst_kruskal(graph, n, graph.size());
        cout << r.best << ' ' << r.second_best << '\n';


    }

    return 0;
}
