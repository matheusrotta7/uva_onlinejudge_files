#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

void floyd_warshall (vector<vector<int>> &weights, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> weights(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                weights[i][j] = 0;
            else
                weights[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        weights[u][v] = w;
    }

    floyd_warshall(weights, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) cout << ' ';
            if (weights[i][j] > INF - 10000)
                cout << "INF";
            else
                cout << weights[i][j];
        }
        cout << '\n';
    }

    return 0;
}
