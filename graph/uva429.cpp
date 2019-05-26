#include <bits/stdc++.h>

#define INF 99999

using namespace std;

int global = 0;

typedef struct node {
    char word[11];
    int access;
    node* next;
    bool visitted;
    int distance;
} node;

bool one_letter_diff(char a[], char b[]) {
    if (strlen(a) != strlen (b)) return false;
    int counter = 0;
    for (int i = 0; i < strlen (a); i++) {
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
    queue<node> Q;
    Q.push(graph[source]);
    while (!Q.empty()) {
        node* u = &(Q.front());
        Q.pop();
        node* v = u->next;
        while (v != NULL) {
            if (graph[v->access].visitted == false) {
                graph[v->access].visitted = true;
                graph[v->access].distance = graph[u->access].distance + 1;
                if (v->access == destination) return graph[v->access].distance;
                Q.push(graph[v->access]);
            }
            v = v->next;
        }
    }
    return -1;
}

int main () {
    int num_of_tests;
    scanf("%d", &num_of_tests);
    for (int i = 0; i < num_of_tests; i++) {
        global = 0;
        node graph[200];
        unordered_map<string, int> ref;
        int index = 0;
        while (index < 200) {
            scanf("%s\n", graph[index].word);
            graph[index].next = NULL;
            graph[index].access = index;
            if (strcmp(graph[index].word, "*") == 0) break;
            ref.insert(pair<string, int>(graph[index].word, index));
            global++;
            for (int j = 0; j < index; j++) {
                if(one_letter_diff(graph[j].word, graph[index].word)) {
                    node* newt;
                    newt = (node*) malloc (sizeof(node));
                    strcpy (newt->word, graph[index].word);
                    newt->access = graph[index].access;
                    newt->next = graph[j].next;
                    graph[j].next = newt;
                    /*------------------*/
                    node* kim;
                    kim = (node*) malloc (sizeof(node));
                    strcpy (kim->word, graph[j].word);
                    kim->access = graph[j].access;
                    kim->next = graph[index].next;
                    graph[index].next = kim;
                }
            }
            index++;
        }

        string line;
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
        printf("\n");
        for (int i = 0; i < global; i++) { //free lists
            node* cur = graph[i].next;
            node* prev;
            while (cur != NULL) {
                prev = cur;
                cur = cur->next;
                free (prev);
            }
        }
    }
    return 0;
}
