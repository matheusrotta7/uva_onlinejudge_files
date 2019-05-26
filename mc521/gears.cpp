#include <bits/stdc++.h>

using namespace std;

typedef struct par {
    int x;
    int y;
} par;


void bfs (vector<vector<int>> graph, int n, vector<int> &colors, vector<vector<char>> &output, int source, vector<bool> &visited, vector<par> gears, vector<bool> blockable) {
    // int count = 0;
    bool bicolorable = true;
    queue<int> q;
    vector<int> all_involved;
    all_involved.push_back(source);
    // vector<bool> visited(n, false);
    // vector<int> predec(n, -1);
    q.push(source);
    visited[source] = true;
    // count++;
    // colors[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        int cur_color = colors[u]; //should be 0 or 1
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            all_involved.push_back(v);
            if (cur_color == 1) {
                if (colors[v] == -1) {
                    colors[v] = 0;
                }
                else if (colors[v] == 1) {
                    bicolorable = false;
                }
            }

            if (cur_color == 0) {
                if (colors[v] == -1) {
                    colors[v] = 1;
                }
                else if (colors[v] == 0) {
                    bicolorable = false;
                }
            }

            if (!visited[v]) {
                visited[v] = true;
                // count++;
                // predec[v] = u;
                q.push(v);
            }
        }
    }
    int ai_size = all_involved.size();
    for (int i = 0; i < ai_size; i++) {

        int aux = all_involved[i];
        par cur = gears[aux];
        int cx = cur.x-1;
        int cy = cur.y-1;
        if (bicolorable) {
            if (colors[aux] == 1)
                output[cx][cy] = '(';
            else
                output[cx][cy] = ')';
        }
        else {
            
                output[cx][cy] = 'B';

        }
    }


    // return (count == n);

}



int main() {

    int r, c;
    scanf("%d %d\n", &r, &c);
    while (r != 0 || c != 0) {
        int num_of_v = 0;
        vector<vector<char>> engine(r+5, vector<char>(c+5, '.'));
        vector<vector<int>> engine_gvalues(r+5, vector<int>(c+5, -1));
        vector<bool> initials;
        vector<par> gears;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char aux;
                scanf("%c", &aux);
                if (aux == '\n') //discard it
                    scanf("%c", &aux);

                engine[i+1][j+1] = aux;
                if (aux != '.') {
                    par bnew;
                    bnew.x = i+1;
                    bnew.y = j+1;
                    engine_gvalues[i+1][j+1] = num_of_v;

                    gears.push_back(bnew);
                    initials.push_back(aux == 'I');
                    num_of_v++;
                }
            }
        }
        vector<vector<int>> gear_graph(num_of_v);
        vector<bool> blockable(num_of_v, false);
        // int cur_v = 0;
        for (int i = 0; i < num_of_v; i++) { //loop to create edges
            bool try_to_block = false;
            par cur;
            cur = gears[i];
            int cx = cur.x;
            int cy = cur.y;
            if (initials[i]) {
                try_to_block = true;
                blockable[i] = true;
            }
            if (engine[cx-1][cy+1] != '.') {
                int wb = engine_gvalues[cx-1][cy+1];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }
            if (engine[cx][cy+1] != '.') {
                int wb = engine_gvalues[cx][cy+1];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }
            // if (engine[cx+1][cy+1] != '.') {
            //     int wb = engine_gvalues[cx+1][cy+1];
            //     if (try_to_block)
            //         blockable[wb] = true;
            //     gear_graph[i].push_back(wb);
            //     gear_graph[wb].push_back(i);
            // }
            if (engine[cx-1][cy] != '.') {
                int wb = engine_gvalues[cx-1][cy];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }
            if (engine[cx+1][cy] != '.') {
                int wb = engine_gvalues[cx+1][cy];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }
            // if (engine[cx-1][cy-1] != '.') {
            //     int wb = engine_gvalues[cx-1][cy-1];
            //     if (try_to_block)
            //         blockable[wb] = true;
            //     gear_graph[i].push_back(wb);
            //     gear_graph[wb].push_back(i);
            // }
            if (engine[cx][cy-1] != '.') {
                int wb = engine_gvalues[cx][cy-1];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }
            if (engine[cx+1][cy-1] != '.') {
                int wb = engine_gvalues[cx+1][cy-1];
                if (try_to_block)
                    blockable[wb] = true;
                gear_graph[i].push_back(wb);
                gear_graph[wb].push_back(i);
            }


        }
        vector<int> colors(num_of_v, -1); //-1 means no color assigned
        vector<bool> visitted(num_of_v, false);
        vector<vector<char>> output(r, vector<char>(c, '.'));
        for (int i = 0; i < num_of_v; i++) {
            if (initials[i]) {
                colors[i] = 1; //clockwise = 1; counter-clockwise = 0;
            }
        }
        for (int i = 0; i < num_of_v; i++) {
            if (initials[i] && !visitted[i]) {
                bfs (gear_graph, num_of_v, colors, output, i, visitted, gears, blockable);
            }
        }

        for (int i = 0; i < num_of_v; i++) {
            if (!visitted[i]) {
                par cur = gears[i];
                int cx = cur.x-1;
                int cy = cur.y-1;
                output[cx][cy] = 'F';
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", output[i][j]);
            }
            printf("\n");
        }




        scanf("%d %d\n", &r, &c);
    }



    return 0;
}
