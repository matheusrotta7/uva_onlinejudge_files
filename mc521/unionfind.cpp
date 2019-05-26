#include <bits/stdc++.h>

using namespace std;

// int parent[1000002];
// int rank_[1000002];

void make_set (int x, vector<int> &parent, vector<int> &rank_) {
    parent[x] = x;
    rank_[x] = 0;
}

int find_set (int x, vector<int> &parent) {
    if (x != parent[x])
        parent[x] = find_set (parent[x], parent);
    return parent[x];
}

void link (int x, int y, vector<int> &parent, vector<int> &rank_) {
    if (rank_[x] > rank_[y])
        parent[y] = x;
    else
        parent[x] = y;
        if (rank_[x] == rank_[y])
            rank_[y]++;
}

void unite (int x, int y, vector<int> &parent, vector<int> &rank) {
    link(find_set(x, parent), find_set(y, parent), parent, rank);
}


int main() {

    int n, q;
    scanf("%d %d\n", &n, &q);
    vector<int> parent(n);
    vector<int> rank(n);

    for (int i = 0; i < n; i++) {
        make_set(i, parent, rank);
    }

    for (int i = 0; i < q; i++) {
        char op;
        int a, b;
        scanf("%c %d %d\n", &op, &a, &b);
        // a += 1;
        // b += 1;
        if (op == '=') {
            unite (a, b, parent, rank);
        }
        else if (op == '?') {
            if (find_set(a, parent) == find_set(b, parent)) {
                cout << "yes\n";
            }
            else
                cout << "no\n";
        }
    }

    return 0;
}
