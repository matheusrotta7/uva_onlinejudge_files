#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    list<int> adj;
    bool visitted;
    int finish;
} node;

typedef struct help {
    int ac;
    int end;
} help;

list<help> l;
node tasks[2001];
node tasks_t[2001];
int t;

void dfs_visit(int u) {
    tasks[u].visitted = true;
    t++;
    for (auto it = tasks[u].adj.begin(); it != tasks[u].adj.end(); it++) {
        int v = *it;
        if (tasks[v].visitted == false) {
            dfs_visit (v);
        }
    }
    tasks[u].finish = ++t;
    help h;
    h.ac = u;
    h.end = t;
    l.push_back(h);
}

void dfs (int n) {
    t = 0;
    for (int i = 0; i < n; i++) {
        tasks[i].visitted = false; //zera as cores
    }
    for (int i = 0; i < n; i++) {
        if (tasks[i].visitted == false)
            dfs_visit(i);
    }
}

void dfs_visit_t(int u) {
    tasks_t[u].visitted = true;
    t++;
    for (auto it = tasks_t[u].adj.begin(); it != tasks_t[u].adj.end(); it++) {
        int v = *it;
        if (tasks_t[v].visitted == false) {
            dfs_visit_t (v);
        }
    }
    tasks_t[u].finish = ++t;
}

bool dfs_t (int n) {
    t = 0;
    for (int i = 0; i < n; i++) {
        tasks_t[i].visitted = false; //zera as cores
    }
    int counter = 0;
    for (auto it = l.begin(); it != l.end(); it++) {
        int i = (*it).ac;
        if (tasks_t[i].visitted == false) {

            if (counter == 1) return false;
            counter++;
            dfs_visit_t(i);
        }
    }
    return true;
}


void transpose (int n) {
    for (int i = 0; i < n; i++) {
        for (auto it = tasks[i].adj.begin(); it != tasks[i].adj.end(); it++) {
            int reached = *it;
            tasks_t[reached].adj.push_back(i);
        }
    }
}

bool comp (help a, help b) {
    return a.end > b.end;
}

bool scc (int n) {
    dfs(n);
    transpose(n);
    l.sort(comp);
    return dfs_t(n);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        int v, w, p;
        l.clear();
        for (int i = 0; i < n; i++) {
            tasks[i].adj.clear();
            tasks_t[i].adj.clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> v >> w >> p;
            v--;
            w--; //work with 0 indices
            tasks[v].adj.push_back(w);
            if (p == 2)
                tasks[w].adj.push_back(v);
        }
        cout << scc(n) << '\n';
        cin >> n >> m;
    }





    return 0;
}
