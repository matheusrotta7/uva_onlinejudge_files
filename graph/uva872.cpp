#include<bits/stdc++.h>

using namespace std;

typedef struct node {
    list<int> adj;
    bool visitted;
} node;

typedef struct wrapper {
    int degree[21];
} wrapper;

node tasks[21];
list<list<int>> answer;

bool comp (list<int> a, list<int> b) {
    for (auto it_a = a.begin(), it_b = b.begin(); it_a != a.end(); it_a++, it_b++) {
        if (*it_a < *it_b) return true;
        else if (*it_a > *it_b) return false;
    }
    return false;
}

void topological_recursive (list<int> L, wrapper w, int cur, list<int> aux) {
    L.remove(cur);
    for (auto it = tasks[cur].adj.begin(); it != tasks[cur].adj.end(); it++) {
        if (--w.degree[*it] == 0) L.push_back(*it);
    }

    if (L.empty()) {
        answer.push_back(aux);
    }

    for (auto it = L.begin(); it != L.end(); it++) {
        int chosen = *it;
        // L.erase(it);
        aux.push_back(chosen);
        topological_recursive (L, w, chosen, aux);
        // L.push_front(chosen);
        aux.pop_back();
    }
}

void topological_sort(int n) {
    wrapper w;
    for (int i = 0; i < n; i++) w.degree[i] = 0;
    for (int i = 0; i < n; i++) {
        for (auto it = tasks[i].adj.begin(); it != tasks[i].adj.end(); it++) w.degree[*it]++;
    }
    list<int> L;
    for (int i = 0; i < n; i++) {
        if (w.degree[i] == 0)
            L.push_back(i);
    }

    for (auto it = L.begin(); it != L.end(); it++) {
        int chosen = *it;
        list<int> aux;
        aux.push_back(chosen);
        // L.erase(it);
        topological_recursive (L, w, chosen, aux);
        // L.push_front(chosen);
        aux.pop_back();
    }

}


int main() {

    int cases;
    cin >> cases;
    char c = getchar();
    unordered_map<char, int> char_to_int;
    unordered_map<int, char> int_to_char;

    for (int i = 0; i < cases; i++) {
        char_to_int.clear();
        int_to_char.clear();
        for (int i = 0; i < 21; i++) tasks[i].adj.clear(); //zera as listas
        answer.clear(); //zera a lista resposta
        char var;
        int counter = 0;
        c = getchar(); //skips blank line

        do {
            var = getchar();
            char_to_int.insert(pair<char, int>(var, counter));
            int_to_char.insert(pair<int, char>(counter, var));
            counter++;
        }
        while (getchar() != '\n');

        char from, to, minor;
        do {
            from = getchar();
            minor = getchar();
            to = getchar();
            tasks[char_to_int[from]].adj.push_back(char_to_int[to]);
        }
        while (getchar() != '\n');

        topological_sort(counter);

        for (auto it = answer.begin(); it != answer.end(); it++) {
            for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
                *it2 = int_to_char[*it2];
            }
        }
        if (answer.empty())
            printf("NO\n");
        else {
            answer.sort (comp);
        }
        for (auto it = answer.begin(); it != answer.end(); it++) {
            for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
                cout << (char) *it2;
                if (next(it2) == (*it).end())
                cout << '\n';
                else
                cout << ' ';
            }

        }
        if (i != cases - 1) cout << '\n';
    }

    return 0;
}
