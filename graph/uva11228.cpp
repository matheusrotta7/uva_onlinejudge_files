#include <bits/stdc++.h>

using namespace std;

int parent[1001];
int rank_[1001];

int states[1001];
int rank_states[1001];

typedef struct result {
    double road;
    double railroad;
} result;

void make_set_st (int x) {
    states[x] = x;
    rank_states[x] = 0;
}

int find_set_st (int x) {
    if (x != states[x])
        states[x] = find_set_st (states[x]);
    return states[x];
}

void link_st (int x, int y) {
    if (rank_states[x] > rank_states[y])
        states[y] = x;
    else
        states[x] = y;
        if (rank_states[x] == rank_states[y])
            rank_states[y]++;
}

void unite_st (int x, int y) {
    link_st(find_set_st(x), find_set_st(y));
}

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

result mst_kruskal(vector<edge> graph, int n, int m, int thr) {
    result r;
    r.road = 0;
    r.railroad = 0;
    for (int i = 0; i < n; i++) {
        make_set(i);
        make_set_st(i);
    }
    sort(graph.begin(), graph.end(), comp);
    for (int i = 0; i < m; i++) {
        int u, v;
        double w;
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        if (find_set(u) != find_set(v)) {
            if (w <= thr) {
                r.road += w;
                unite_st(u, v);
            }
            else
                r.railroad += w;
            unite(u, v);
        }
    }
    return r;
}

int main() {
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        vector<edge> graph;
        vector<point> points;
        int n, r;
        cin >> n >> r;
        for (int j = 0; j < n; j++) {
            parent[i] = -1;
            rank_[i] = -1;

            states[i] = -1;
            rank_states[i] = -1;
        }
        bool aux[1001];
        for (int j = 0; j < n; j++) {
            aux[j] = false;
        }
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            point p;
            p.id = j;
            p.x = x;
            p.y = y;
            points.push_back(p);
        }
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                edge e;
                point a = points[j];
                point b = points[k];
                e.u = a.id;
                e.v = b.id;
                e.w = sqrt(pow((double)a.x - b.x, 2.0) + pow((double)a.y - b.y, 2.0));
                graph.push_back(e);
            }
        }
        result re = mst_kruskal(graph, n, graph.size(), r);
        for (int j = 0; j < n; j++) {
            find_set_st(j); //compress them
        }
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (aux[states[j]] == false) {
                counter++;
                aux[states[j]] = true;
            }
        }
        cout << "Case #" << i+1 << ": "<< counter << ' ' << (int) round(re.road) << ' ' << (int) round(re.railroad) << '\n';
    }

    return 0;
}
