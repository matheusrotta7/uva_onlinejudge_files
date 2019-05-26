#include<bits/stdc++.h>

using namespace std;

typedef struct warboy {
    int x;
    int y;
} warboy;

void dfs_visit (int i, vector<vector<int>> &graph, vector<bool> &visited) {
     visited[i] = true;

     for (int j = 0; j < graph[i].size(); j++) {
         int cur = graph[i][j];
         if (!visited[cur]) {
             dfs_visit(cur, graph, visited);
         }
     }
}

int dfs (vector<vector<int>> graph) {
    int n = graph.size();
    int counter = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            counter++;
            dfs_visit(i, graph, visited);
        }
    }
    return counter;
}

int main() {


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n);
        vector<warboy> wbs(n);
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            wbs[j].x = x;
            wbs[j].y = y;
        }

        //add edge logic
        //edges will be bidirectional
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (abs(wbs[j].x - wbs[k].x) <= 1 && abs(wbs[j].y - wbs[k].y) <= 1) {
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }

        //now dfs can tell us the number of connected components!
        int ncc = dfs(graph);
        cout << "Case " << i+1 << ": " << ncc << '\n';

    }



    return 0;
}
