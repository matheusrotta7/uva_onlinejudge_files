#include <bits/stdc++.h>

using namespace std;

int parent[1001];
int rank_[1001];

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


vector<edge> mst_kruskal(vector<edge> graph, int n, int m) {
    vector<edge> mst;
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
            mst.push_back(graph[i]);
            unite(u, v);
        }
    }
    return mst;
}

int main() {
    int num_of_tests;
    cin >> num_of_tests;

    for (int i = 0; i < num_of_tests; i++) {
        vector<edge> graph;
        vector<point> points;
        int s, p;
        cin >> s >> p;

        for (int j = 0; j < p; j++) {
            parent[i] = -1;
            rank_[i] = -1;
        }

        for (int j = 0; j < p; j++) {
            int x, y;
            cin >> x >> y;
            point p;
            p.id = j;
            p.x = x;
            p.y = y;
            points.push_back(p);
        }
        for (int j = 0; j < p; j++) {
            for (int k = j+1; k < p; k++) {
                edge e;
                point a = points[j];
                point b = points[k];
                e.u = a.id;
                e.v = b.id;
                e.w = sqrt(pow((double)a.x - b.x, 2.0) + pow((double)a.y - b.y, 2.0));
                graph.push_back(e);
            }
        }
        vector<edge> mst;
        vector<bool> has_sat(p, false);
        mst = mst_kruskal(graph, p, graph.size());
        int removable_edges = s-1;
        if (removable_edges >= mst.size())
            cout << "0\n";
        else
            printf("%.2lf\n", mst[mst.size()-1-removable_edges].w);
        // int j = mst.size() - 1;
        // while (s > 0 && !mst.empty()) {
        //     edge cur = mst.back();
        //     if (s == 1) {
        //         if (has_sat[cur.u] || has_sat[cur.v]) {
        //             s--;
        //             has_sat[cur.u] = true;
        //             has_sat[cur.v] = true;
        //             mst.pop_back();
        //         }
        //         else {
        //             s--;
        //         }
        //     }
        //     else { //means s >= 2
        //         if (has_sat[cur.u] || has_sat[cur.v]) {
        //             s--;
        //             has_sat[cur.u] = true;
        //             has_sat[cur.v] = true;
        //             mst.pop_back();
        //
        //         }
        //         else {
        //             s -= 2;
        //             has_sat[cur.u] = true;
        //             has_sat[cur.v] = true;
        //             mst.pop_back();
        //         }
        //     }
        // }
        
        // cout << "Case #" << i+1 << ": "<< counter << ' ' << (int) round(re.road) << ' ' << (int) round(re.railroad) << '\n';
    }

    return 0;
}
