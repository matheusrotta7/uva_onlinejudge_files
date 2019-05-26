#include<bits/stdc++.h>
#define INF 9999999
#define NIL -1

using namespace std;

vector<int> dijkstra (vector<vector<int>> graph, vector<vector<int>> w, int source) {
    // int source = 0;
    // int destination = graph.size() - 1;
    int num_vertexes = graph.size();

    vector<int> distance(num_vertexes, INF);
    vector<int> predecessor(num_vertexes, NIL);
    distance[source] = 0;

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    for (int i = 0; i < num_vertexes; i++) {
        Q.push(pair<int,int>(distance[i], i));
    }
    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (distance[v] > distance[u] + w[u][v]) {
                distance[v] = distance[u] + w[u][v];
                predecessor[v] = u;
                Q.push(pair<int,int>(distance[v], v));
            }
        }
    }

    return distance;
}

int main() {

    int n;
    cin >> n;
    while (n != 0) {
        vector<vector<int>> graph_miguel(26);
        vector<vector<int>> graph_shahriar(26);
        vector<vector<int>> weights_miguel(26, vector<int>(26));
        vector<vector<int>> weights_shahriar(26, vector<int>(26));
        for (int i = 0; i < n; i++) {
            char age, dir, pl1, pl2;
            cin >> age >> dir >> pl1 >> pl2;
            int cost;
            cin >> cost;
            int u, v;
            u = pl1 - 65; //ascii adjustment
            v = pl2 - 65;
            if (age == 'Y') {
                graph_shahriar[u].push_back(v);
                weights_shahriar[u][v] = cost;
                if (dir == 'B') {
                    graph_shahriar[v].push_back(u);
                    weights_shahriar[v][u] = cost;
                }
            }
            else {
                graph_miguel[u].push_back(v);
                weights_miguel[u][v] = cost;
                if (dir == 'B') {
                    graph_miguel[v].push_back(u);
                    weights_miguel[v][u] = cost;
                }
            }
        }
        char place_shahriar, place_miguel;
        cin >> place_shahriar >> place_miguel;
        // if (place_miguel == place_shahriar) {
        //     cout << "0 " << place_miguel << '\n';
        // }
        // else {
        int source_miguel = place_miguel - 65;
        int source_shahriar = place_shahriar - 65;
        vector<int> distance_miguel = dijkstra (graph_miguel, weights_miguel, source_miguel);
        vector<int> distance_shahriar = dijkstra (graph_shahriar, weights_shahriar, source_shahriar);
        int cur_min = 3*INF;
        char place_min = '-';
        vector<int> places;
        for (int i = 0; i < 26; i++) {
            int dist = distance_miguel[i] + distance_shahriar[i];
            if (cur_min > dist) {
                places.clear();
                places.push_back(i);
                cur_min = dist;
            }
            else if (cur_min == dist) {
                places.push_back(i);
            }
        }
        sort(places.begin(), places.end());
        if (cur_min >= INF)
            cout << "You will never meet.\n";
        else {
            cout << cur_min;
            for (int i = 0; i < places.size(); i++) {
                cout << ' ' << (char) (places[i] + 65);
            }
            cout << '\n';
        }

        // }

        cin >> n;
    }

    return 0;
}
