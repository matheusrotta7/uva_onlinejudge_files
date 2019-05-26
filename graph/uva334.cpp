#include<bits/stdc++.h>
#define INF 99999999

using namespace std;

void bfs (vector<vector<int>> graph, int source, vector<vector<bool>> &concurrent) {
    int n = graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> distance(n, INF);

    q.push(source);
    visited[source] = true;
    distance[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            concurrent[source][v] = false;
            concurrent[v][source] = false;
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    // return distance;
}


int main() {

    int nc;
    cin >> nc;

    int rick = 1;

    while (nc != 0) {

        vector<vector<int>> graph(300);
        unordered_map<string, int> stoi;
        unordered_map<int, string> itos;
        int counter = -1;
        int vertexes = 0;

        for (int i = 0; i < nc; i++) {
            int ne;
            cin >> ne;
            bool first = true;
            for (int j = 0; j < ne; j++) {
                vertexes++;
                string s;
                cin >> s;
                stoi.insert(pair<string,int>(s, ++counter));
                itos.insert(pair<int,string>(counter, s));
                if (first)
                    first = !first;
                else {
                    graph[counter-1].push_back(counter);
                }
            }
        }

        int nm;
        cin >> nm;
        for (int j = 0; j < nm; j++) {
            string s, t;
            cin >> s >> t;
            int u, v;
            u = stoi[s];
            v = stoi[t];
            graph[u].push_back(v);
        }

        vector<vector<bool>> concurrent(vertexes, vector<bool>(vertexes, true));
        for (int i = 0; i < vertexes; i++) {
            bfs(graph, i, concurrent);
        }
        int conc_count = 0;
        vector<pair<string,string>> conc_pairs;
        for (int i = 0; i < vertexes; i++) {
            for (int j = i+1; j < vertexes; j++) {
                if (concurrent[i][j]) {
                    conc_count++;
                    conc_pairs.push_back(pair<string,string>(itos[i], itos[j]));
                }
            }
        }
        if (conc_count != 0) {
            cout << "Case " << rick++ << ", " << conc_count << " concurrent events:\n";
            for (int i = 0; i < conc_count; i++) {
                // if (i != 0) cout << ' ';
                printf("(%s,%s) ", conc_pairs[i].first.c_str(), conc_pairs[i].second.c_str());
                if (i == 1) break;
            }
            cout << '\n';
        }
        else
            cout << "Case " << rick++ << ", no concurrent events.\n";

        cin >> nc;
    }

    return 0;
}
