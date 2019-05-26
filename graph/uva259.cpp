#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

// typedef struct edge {
//     int v;
//     int w;
// } edge;

bool bfs (vector<vector<int>> graph, vector<vector<int>> &weights, vector<vector<int>> &flux, int source, int destination) {
    bool has_path = false;
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> predec(n, -1);
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];

            if (!visited[v] && weights[u][v] != 0) {
                visited[v] = true;
                predec[v] = u;
                if (v == destination) {
                    has_path = true;
                    break;
                }
                q.push(v);
            }
        }
    }

    if (has_path) {
        int cur = destination;
        int min_ = INF;
        while (predec[cur] != -1) {
            min_ = min(min_, weights[predec[cur]][cur]);
            cur = predec[cur];
        }
        cur = destination;
        while (predec[cur] != -1) {
            weights[predec[cur]][cur] -= min_;
            weights[cur][predec[cur]] += min_;
            flux[predec[cur]][cur] += min_;
            flux[cur][predec[cur]] = -flux[predec[cur]][cur];
            cur = predec[cur];
        }
    }
    return has_path;
}

int edmonds_karp (vector<vector<int>> graph, vector<vector<int>> weights, vector<vector<int>> &flux, int s, int t) {
    while (bfs(graph, weights, flux, s, t));
    int sum = 0;
    for (int i = 0; i < graph[s].size(); i++) {
        int v = graph[s][i];
        sum += flux[s][v];
    }
    return sum;
}

int main() {

    vector<vector<int>> residual_net(38);
    vector<vector<int>> weights(38, vector<int>(38, 0));
    vector<vector<int>> flux(38, vector<int>(38, 0));
    string line;
    int total_clients = 0;
    while (getline(cin, line)) {
        if (line == "") {
            for (int i = 27; i <= 36; i++) {
                residual_net[i].push_back(37);
                residual_net[37].push_back(i);
                weights[i][37] = 1;
                weights[37][i] = 0;
            }
            int max_flow = edmonds_karp(residual_net, weights, flux, 0, 37);
            if (max_flow == total_clients) {
                for (int i = 27; i <= 36; i++) {
                    bool aloc = false;
                    for (int j = 1; j <= 26; j++) {
                        if (flux[j][i] == 1) {
                            cout << (char)(j+64);
                            aloc = true;
                            break;
                        }
                    }
                    if (!aloc)
                        cout << '_';
                }
                cout << '\n';
            }
            else {
                cout << "!\n";
            }
            for (int i = 0; i < 38; i++) {
                residual_net[i].clear();
                for (int j = 0; j < 38; j++) {
                    weights[i][j] = 0;
                    flux[i][j] = 0;
                }
            }
            // residual_net.clear();
            total_clients = 0;
            continue;
        }
        stringstream ss(line);
        char app;
        int num_clients;
        ss >> app >> num_clients;
        residual_net[0].push_back(app-64); //from source to app
        residual_net[app-64].push_back(0);
        weights[0][app-64] = num_clients;
        weights[app-64][0] = 0;
        total_clients += num_clients;
        char c;
        // ss >> blank;
        ss >> c;
        while (c != ';') {
            residual_net[app-64].push_back(c-48+27);
            residual_net[c-48+27].push_back(app-64);
            weights[app-64][c-48+27] = 1;
            weights[c-48+27][app-64] = 0;
            ss >> c;
        }

    }
    for (int i = 27; i <= 36; i++) {
        residual_net[i].push_back(37);
        residual_net[37].push_back(i);
        weights[i][37] = 1;
        weights[37][i] = 0;
    }
    int max_flow = edmonds_karp(residual_net, weights, flux, 0, 37);
    if (max_flow == total_clients) {
        for (int i = 27; i <= 36; i++) {
            bool aloc = false;
            for (int j = 1; j <= 26; j++) {
                if (flux[j][i] == 1) {
                    cout << (char)(j+64);
                    aloc = true;
                    break;
                }
            }
            if (!aloc)
                cout << '_';
        }
        cout << '\n';
    }
    else {
        cout << "!\n";
    }

    return 0;
}
