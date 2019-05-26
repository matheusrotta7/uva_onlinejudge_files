#include<bits/stdc++.h>

using namespace std;

void dfs_visit (vector<vector<int>> graph, int u, list<int> &ts, vector<bool> &visited) {
    int aux = graph[u].size();
    for (int i = 0; i < aux; i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            visited[v] = true;
            dfs_visit(graph, v, ts, visited);
            ts.push_front(v);
        }
    }
}

list<int> topological_sort (vector<vector<int>> graph, int n) {
    list<int> ts;
    // int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs_visit(graph, i, ts, visited);
            ts.push_front(i);
        }
    }
    return ts;
}

int dag_shortest_paths(vector<vector<int>> graph, int n) {
    // int n = graph.size();
    list<int> ts = topological_sort(graph, n);
    vector<int> distance(n, 0);
    int cur_min = 1;
    for (auto it = ts.begin(); it != ts.end(); it++) {
        int u = *it;
        int aux = graph[u].size();
        for (int j = 0; j < aux; j++) {
            int v = graph[u][j];
            distance[v] = min(distance[v], distance[u]-1);
            // cur_min = min(cur_min, distance[v]);
        }
    }
    for (int i = 0; i < n; i++) {
        cur_min = min(cur_min, distance[i]);
    }
    return cur_min;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        int r, c;
        cin >> s >> r >> c;
        vector<vector<int>> m(r, vector<int>(c));
        int g_size = r*c;
        vector<vector<int>> graph(g_size);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> m[j][k];
            }
        }

        if (r == 1 || c == 1) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (j != 0) {
                        if (m[j][k] > m[j-1][k])
                        graph[c*j+k].push_back(c*(j-1) + k);
                    }
                    if (k != 0) {
                        if (m[j][k] > m[j][k-1])
                        graph[c*j+k].push_back(c*(j) + k-1);
                    }
                    if (j != r-1) {
                        if (m[j][k] > m[j+1][k])
                        graph[c*j+k].push_back(c*(j+1) + k);
                    }
                    if (k != c-1) {
                        if (m[j][k] > m[j][k+1])
                        graph[c*j+k].push_back(c*(j) + k+1);
                    }
                }
            }

        }
        else{
            for (int j = 1; j < r-1; j++) {
                for (int k = 1; k < c-1; k++) {

                    if (m[j][k] > m[j-1][k])
                    graph[c*j+k].push_back(c*(j-1) + k);


                    if (m[j][k] > m[j][k-1])
                    graph[c*j+k].push_back(c*j + k-1);


                    if (m[j][k] > m[j+1][k])
                    graph[c*j+k].push_back(c*(j+1) + k);


                    if (m[j][k] > m[j][k+1])
                    graph[c*j+k].push_back(c*j + k+1);

                }
            }

            if (m[0][0] > m[0][1])
            graph[0].push_back(1);

            if (m[0][0] > m[1][0])
            graph[0].push_back(c);

            if (m[0][c-1] > m[0][c-2])
            graph[c-1].push_back(c-2);

            if (m[0][c-1] > m[1][c-1])
            graph[c-1].push_back(c + c-1);

            if (m[r-1][0] > m[r-2][0])
            graph[c*(r-1)].push_back(c*(r-2));

            if (m[r-1][0] > m[r-1][1])
            graph[c*(r-1)].push_back(c*(r-1) + 1);

            if (m[r-1][c-1] > m[r-2][c-1])
            graph[c*(r-1)+c-1].push_back(c*(r-2) + c-1);

            if (m[r-1][c-1] > m[r-1][c-2])
            graph[c*(r-1)+c-1].push_back(c*(r-1) + c-2);



            for (int k = 1; k < c-1; k++) {


                if (m[0][k] > m[0][k-1])
                graph[k].push_back(k-1);


                if (m[0][k] > m[1][k])
                graph[k].push_back(c + k);


                if (m[0][k] > m[0][k+1])
                graph[k].push_back(k+1);

            }

            for (int k = 1; k < c-1; k++) {


                if (m[r-1][k] > m[r-1][k-1])
                graph[c*(r-1)+k].push_back(c*(r-1)+k-1);


                if (m[r-1][k] > m[r-2][k])
                graph[c*(r-1)+k].push_back(c*(r-2) + k);


                if (m[r-1][k] > m[r-1][k+1])
                graph[c*(r-1)+k].push_back(c*(r-1)+k+1);

            }

            for (int j = 1; j < r-1; j++) {

                if (m[j][0] > m[j-1][0])
                graph[c*j].push_back(c*(j-1));


                if (m[j][0] > m[j+1][0])
                graph[c*j].push_back(c*(j+1));


                if (m[j][0] > m[j][1])
                graph[c*j].push_back(c*j +1);

            }

            for (int j = 1; j < r-1; j++) {

                if (m[j][c-1] > m[j-1][c-1])
                graph[c*j+c-1].push_back(c*(j-1) + c-1);


                if (m[j][c-1] > m[j][c-2])
                graph[c*j+c-1].push_back(c*(j) + c-2);


                if (m[j][c-1] > m[j+1][c-1])
                graph[c*j+c-1].push_back(c*(j+1) + c-1);

            }

        }



        int longest = abs(dag_shortest_paths(graph, g_size))+1;
        cout << s << ": " << longest << '\n';
    }

    return 0;
}
