#include <bits/stdc++.h>

#define INF 99999

using namespace std;

typedef struct node {
    list<int> adj;
    bool visitted;
    int distance;
} node;

int counter[2502];

void zero_counter() {
    for (int i = 0; i < 2502; i++) counter[i] = 0;
}

void print_stuff() {
    int M = -1, D = -1;
    for (int i = 0; i < 2502; i++) {
        if (counter[i] > M) {
            M = counter[i];
            D = i;
        }
    }
    if (M == 0) printf("0\n");
    else printf("%d %d\n", M, D);
}


void bfs (node graph[], int source) {
    zero_counter();
    for (int i = 0; i < 2501; i++) {
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
                counter[graph[v].distance]++;
                Q.push(v);
            }
        }
    }
    //return ;
}

int main () {

    node graph[2501];
    int employees;
    scanf("%d", &employees);
    for (int i = 0; i < employees; i++) {
        int num_of_friends;
        scanf("%d", &num_of_friends);
        for (int j = 0; j < num_of_friends; j++) {
            int pal;
            scanf("%d", &pal);
            graph[i].adj.push_back(pal);
            // graph[pal].adj.push_back(i); //comentar essa linha
        }
    }
    int num_of_tests;
    scanf("%d", &num_of_tests);
    for (int i = 0; i < num_of_tests; i++) {
        int source;
        scanf("%d", &source);
        bfs (graph, source);
        print_stuff();
    }


    return 0;
}
