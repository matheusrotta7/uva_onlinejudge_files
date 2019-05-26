#include <bits/stdc++.h>

#define INF 99999

using namespace std;

typedef struct node {
    string word;
    list<int> adj;
    bool visitted;
    int distance;
} node;



bool one_letter_diff(string a, string b) {
    if (a.size() != b.size()) return false;
    int counter = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) counter++;
    }
    if (counter == 1) return true;
    else return false;
}

int bfs (node graph[], int source, int destination) {
    for (int i = 0; i < 200; i++) {
        graph[i].visitted = false;
        graph[i].distance = INF;
    }
    graph[source].visitted = true;
    graph[source].distance = 0;
    queue<int> Q;
    Q.push(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        list<int>::iterator it;
        for (it = graph[u].adj.begin(); it != graph[u].adj.end(); it++) {
            int v = *it;
            if (graph[v].visitted == false) {
                graph[v].visitted = true;
                graph[v].distance = graph[u].distance + 1;
                if (v == destination) return graph[v].distance;
                Q.push(v);
            }
        }
    }
    return -1;
}

int main () {
    int num_of_tests;
    scanf("%d", &num_of_tests);
    for (int i = 0; i < num_of_tests; i++) {
        node graph[210];
        unordered_map<string, int> ref;
        int index = 0;
        while (true) {
            cin >> graph[index].word;
            if (graph[index].word == "*") break;
            ref.insert(pair<string, int>(graph[index].word, index));

            for (int j = 0; j < index; j++) {
                if(one_letter_diff(graph[j].word, graph[index].word)) {

                    graph[j].adj.push_back(index);
                    /*------------------*/

                    graph[index].adj.push_back(j);
                }
            }
            index++;
        }
        // char hijo_de_puta[66];
        // scanf("%s", hijo_de_puta);
        string line;
        // getline(cin, line);
        cin.ignore();
        while (getline(cin, line) && line != "") {
            // ungetc(ver, stdin);
            stringstream ss(line);
            string source, destination;
            ss >> source >> destination;
            int distance;
            if (ref.find(source) == ref.end() || ref.find(destination) == ref.end()) return 0;
            if (source == destination)
                distance = 0;
            else
                distance = bfs (graph, (ref.find(source))->second, (ref.find(destination))->second);
            // printf("%s %s %d\n", source, destination, distance);
            cout << source + ' ' +  destination + ' ' << distance << '\n';
        }
        ref.clear();
        if (i < num_of_tests - 1)
            printf("\n");

    }
    return 0;
}
