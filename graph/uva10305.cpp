#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    list<int> adj;
    bool visitted;
} node;

node tasks[101]; //ok to index from 1 to 100, global because yes
list<int> ts;

void dfs_visit(int u) {
    tasks[u].visitted = true;
    for (auto it = tasks[u].adj.begin(); it != tasks[u].adj.end(); it++) {
        int v = *it;
        if (tasks[v].visitted == false) {
            dfs_visit (v);
        }
    }
    ts.push_front(u);
}

void topological_sort(int n) {
    for (int i = 1; i <= n; i++) {
        tasks[i].visitted = false; //zera as cores
    }
    ts.clear(); //zera a lista resposta
    for (int i = 1; i <= n; i++) {
        if (tasks[i].visitted == false)
            dfs_visit(i);
    }
}

int main () {

    int n, m;
    scanf("%d %d", &n, &m);
    while (n != 0 || m != 0) {
        for (int i = 1; i <= 100; i++) tasks[i].adj.clear(); //zera as listas
        for (int k = 0; k < m; k++) {
            int i, j;
            scanf("%d %d", &i, &j);
            tasks[i].adj.push_back(j);
        }

        topological_sort(n);
        for (auto it = ts.begin(); it != ts.end(); it++) {
            printf("%d", *it);
            if (next(it) != ts.end()) printf(" ");
            else printf("\n");
        }
        scanf("%d %d", &n, &m);
    }

    return 0;
}
