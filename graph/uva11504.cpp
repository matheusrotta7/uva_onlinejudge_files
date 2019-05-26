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

list<int> topological;
list<help> l;
node tasks[100001];
node tasks_t[100001];
node tasks_scc[100001];
node tasks_scc_t[100001];
int t;
unordered_map<int, int> int_to_scc;
// int cur_node;

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

void dfs_visit_final(int u) {
    tasks_scc_t[u].visitted = true;
    for (auto it = tasks_scc_t[u].adj.begin(); it != tasks_scc_t[u].adj.end(); it++) {
        int v = *it;
        if (tasks_scc_t[v].visitted == false) {
            dfs_visit_final (v);
        }
    }
}

int dfs_final (int n) {
    t = 0;
    for (int i = 0; i < n; i++) {
        tasks_scc_t[i].visitted = false; //zera as cores
    }
    int dominos = 0;
    for (auto it = topological.begin(); it != topological.end(); it++) {
        int i = *it;
        if (tasks_scc_t[i].visitted == false) {
            dominos++;
            dfs_visit_final(i);
        }
    }
    return dominos;
}


void dfs_visit_t(int u, int counter) {
    tasks_t[u].visitted = true;
    int_to_scc.insert(pair<int, int>(u, counter));
    t++;
    for (auto it = tasks_t[u].adj.begin(); it != tasks_t[u].adj.end(); it++) {
        int v = *it;
        if (tasks_t[v].visitted == false) {
            dfs_visit_t (v, counter);
        }
        else { //if during dfs(G^t) we find a black node, it is an scc that used to reach this one
            tasks_scc[counter].adj.push_back(int_to_scc[v]);
        }
    }
    tasks_t[u].finish = ++t;
}

void dfs_visit_scc(int u) {
    tasks_scc_t[u].visitted = true;
    for (auto it = tasks_scc_t[u].adj.begin(); it != tasks_scc_t[u].adj.end(); it++) {
        int v = *it;
        if (tasks_scc_t[v].visitted == false) {
            dfs_visit_scc (v);
        }
    }
    topological.push_front(u);
}

void topological_sort(int n) {
    topological.clear();
    for (int i = 0; i < n; i++) {
        tasks_scc_t[i].visitted = false; //zera as cores
    }

    for (int i = 0; i < n; i++) {
        if (tasks_scc_t[i].visitted == false)
            dfs_visit_scc(i);
    }
}

int dfs_t (int n) {
    t = 0;
    int_to_scc.clear();
    for (int i = 0; i < n; i++) {
        tasks_t[i].visitted = false; //zera as cores
    }
    int counter = 0;
    for (auto it = l.begin(); it != l.end(); it++) { //visita em ordem decrescente do tempo de término do prim. dfs
        int i = (*it).ac;
        if (tasks_t[i].visitted == false) {
            int_to_scc.insert(pair<int, int>(i, counter));
            dfs_visit_t(i, counter);
            counter++;
        }
    }
    return counter;
}


void transpose (int n) {
    for (int i = 0; i < n; i++) {
        for (auto it = tasks[i].adj.begin(); it != tasks[i].adj.end(); it++) {
            int reached = *it;
            tasks_t[reached].adj.push_back(i);
        }
    }
}

void transpose_scc (int n) {
    for (int i = 0; i < n; i++) {
        for (auto it = tasks_scc[i].adj.begin(); it != tasks_scc[i].adj.end(); it++) {
            int reached = *it;
            tasks_scc_t[reached].adj.push_back(i);
        }
    }
}

bool comp (help a, help b) {
    return a.end > b.end;
}

int scc (int n) {
    dfs(n);
    transpose(n);
    l.sort(comp);
    int counter = dfs_t(n);
    transpose_scc(counter);
    topological_sort(counter);
    return dfs_final(counter);
}

int main() {
    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++) {
        l.clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            tasks[i].adj.clear();
            tasks_t[i].adj.clear();
            tasks_scc[i].adj.clear();
            tasks_scc_t[i].adj.clear();
        }
        for (int i = 0; i < m; i++) {
            int v, w;
            cin >> v >> w;
            v--;
            w--;
            tasks[v].adj.push_back(w);
        }
        cout << scc(n) << '\n';
    }





    return 0;
}
