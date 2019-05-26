#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

typedef struct triple {
    int v;
    int a;
    int b;
} triple;

bool bfs (vector<vector<int>> graph, vector<vector<int>> &weights, vector<vector<int>> &flux, int source, int destination) {
    bool has_path = false;
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> predec(n, -1);
    vector<int> min_cap(n, INF);
    min_cap[source] = INF;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];

            if (!visited[v] && weights[u][v] != 0) {
                min_cap[v] = min(min_cap[u], weights[u][v]);
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
        int min_ = min_cap[cur];
        // while (predec[cur] != -1) {
        //     min_ = min(min_, weights[predec[cur]][cur]);
        //     cur = predec[cur];
        // }
        // cur = destination;
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

    int n;
    cin >> n;
    int naruto = 1;
    while (n != 0) {
        int m;
        cin >> m;
        vector<triple> monkeys;
        int min_time = INF;
        int max_time = -INF;
        int total_thirst = 0;
        for (int i = 0; i < n; i++) {
            int v, a, b;
            cin >> v >> a >> b;
            b--;
            total_thirst += v;
            min_time = min(min_time, a);
            max_time = max(max_time, b);
            triple cur;
            cur.v = v;
            cur.a = a;
            cur.b = b;
            monkeys.push_back(cur);
        }
        int nt = max_time - min_time + 1;
        int size = 1+n+nt+1;
        vector<vector<int>> residual_net(size);
        vector<vector<int>> weights(size, vector<int>(size, 0));
        vector<vector<int>> flux(size, vector<int>(size, 0));
        for (int i = 0; i < n; i++) {
            triple cur = monkeys[i];
            residual_net[0].push_back(i+1);
            residual_net[i+1].push_back(0);
            weights[0][i+1] = cur.v;
            weights[i+1][0] = 0;
            int time_a = cur.a - min_time + n+1;
            int time_b = cur.b - min_time + n+1;
            for (int j = time_a; j <= time_b; j++) {
                residual_net[i+1].push_back(j);
                residual_net[j].push_back(i+1);
                weights[i+1][j] = 1;
                weights[j][i+1] = 0;
            }
        }
        for (int i = min_time; i <= max_time; i++) {
            int cur = i - min_time + n + 1;
            residual_net[cur].push_back(n+nt+1);
            residual_net[n+nt+1].push_back(cur);
            weights[cur][n+nt+1] = m;
            weights[n+nt+1][cur] = 0;
        }
        int max_flow = edmonds_karp(residual_net, weights, flux, 0, n+nt+1);
        if (total_thirst == max_flow) {
            cout << "Case " << naruto++ << ": Yes\n";
            for (int i = 0; i < n; i++) {
                triple cur = monkeys[i];
                int v, a, b;
                v = cur.v;
                a = cur.a;
                b = cur.b;
                vector<pair<int,int>> intervals;
                int time_a = a - min_time +n+1;
                int time_b = b - min_time +n+1;
                bool growing = false;
                int lower, upper;
                for (int j = time_a; j <= time_b; j++) {
                    if (flux[i+1][j] == 1) {
                        if (!growing) {
                            lower = j;
                            growing = true;
                        }
                        upper = j+1;
                    }
                    else {
                        if (growing) {
                            intervals.push_back(pair<int,int>(lower,upper));
                        }
                        growing = false;
                    }
                }
                if (growing) {
                    intervals.push_back(pair<int,int>(lower,upper));
                }
                cout << intervals.size() << ' ';
                for (int j = 0; j < intervals.size(); j++) {
                    if (j != 0)
                        cout << ' ';
                    cout << "(" << intervals[j].first+min_time-n-1 << "," << intervals[j].second+min_time-n-1 << ")";
                }
                cout << '\n';
            }
        }
        else {
            cout << "Case " << naruto++ << ": No\n";
        }

        cin >> n;
    }

    return 0;
}
