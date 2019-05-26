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

unordered_map<int, string> int_to_string;
unordered_map<string, int> string_to_int;
list<string> aux;
list<list<string>> answer;
list<help> l;
node tasks[30];
node tasks_t[30];
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
    aux.push_back(int_to_string[u]);
}

bool dfs_t (int n) {
    t = 0;
    for (int i = 0; i < n; i++) {
        tasks_t[i].visitted = false; //zera as cores
    }
    for (auto it = l.begin(); it != l.end(); it++) {
        int i = (*it).ac;
        aux.clear();
        if (tasks_t[i].visitted == false) {
            dfs_visit_t(i);
        }
        answer.push_back(aux);
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

void scc (int n) {
    dfs(n);
    transpose(n);
    l.sort(comp);
    dfs_t(n);
}


int main() {
    int n, m;
    cin >> n >> m;
    int loop_count = 1;
    while (n != 0 || m != 0) {
        if (loop_count > 1) cout << '\n';
        answer.clear();
        int_to_string.clear();
        string_to_int.clear();
        string v, w;
        l.clear();
        for (int i = 0; i < n; i++) {
            tasks[i].adj.clear();
            tasks_t[i].adj.clear();
        }
        int ref = 0;
        for (int i = 0; i < m; i++) {
            cin >> v >> w;
            int a, b;

            if (string_to_int.find(v) == string_to_int.end()) {
                string_to_int.insert(pair<string, int>(v, a = ref++));
                int_to_string.insert(pair<int, string>(a, v));
            }
            else {
                a = string_to_int[v];
            }

            if (string_to_int.find(w) == string_to_int.end()) {
                string_to_int.insert(pair<string, int>(w, b = ref++));
                int_to_string.insert(pair<int, string>(b, w));
            }
            else {
                b = string_to_int[w];
            }
            tasks[a].adj.push_back(b);
        }

        scc(ref);
        printf("Calling circles for data set %d:\n", loop_count);
        for (auto it = answer.begin(); it != answer.end(); it++) {
            for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
                cout << *it2;
                if (next(it2) == (*it).end())
                cout << '\n';
                else
                cout << ", ";
            }
        }
        cin >> n >> m;
        loop_count++;
    }

    return 0;
}
