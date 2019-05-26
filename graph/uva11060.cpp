#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    list<int> adj;
    bool visitted;
} node;

node tasks[100];
list<int> ts;

void topological_sort(int n) {
    for (int i = 0; i < n; i++) {
        tasks[i].visitted = false; //zera as cores
        // tasks[i].adj.sort();
    }
    int degree[100];
    for (int i = 0; i < n; i++) degree[i] = 0;
    for (int i = 0; i < n; i++) {
        for (auto it = tasks[i].adj.begin(); it != tasks[i].adj.end(); it++) degree[*it]++;
    }
    list<int> L;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0)
            L.push_back(i);
    }
    while (!L.empty()) {
        int cur = L.front();
        ts.push_back(cur);
        L.pop_front();
        for (auto it = tasks[cur].adj.begin(); it != tasks[cur].adj.end(); it++) {
            if (--degree[*it] == 0) L.push_back(*it);
        }
        L.sort();
    }
}

int main () {


    int n, m;

    unordered_map<string, int> drinks_to_int;
    unordered_map<int, string> ints_to_drink;

    int case_n = 0;

    while (scanf("%d", &n) != EOF) {
        case_n++;
        drinks_to_int.clear(); //zera o hash
        ints_to_drink.clear();
        for (int i = 0; i < 100; i++) tasks[i].adj.clear(); //zera as listas
        ts.clear(); //zera a lista resposta
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            drinks_to_int.insert(pair<string, int>(s, i));
            ints_to_drink.insert(pair<int, string>(i, s));
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            string s, t;
            cin >> s >> t;
            tasks[drinks_to_int[s]].adj.push_back(drinks_to_int[t]);
        }

        topological_sort(n);
        printf("Case #%d: Dilbert should drink beverages in this order: ", case_n);
        for (auto it = ts.begin(); it != ts.end(); it++) {
            cout << ints_to_drink[*it];
            if (next(it) != ts.end()) printf(" ");
            else printf(".\n\n");
        }
    }


    return 0;
}
