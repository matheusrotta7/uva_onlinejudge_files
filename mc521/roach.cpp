#include <bits/stdc++.h>

using namespace std;

typedef struct pair_ {
    int a;
    int b;
} pair_;


vector<vector<bool>> expand_roaches(vector<vector<char>> grid, vector<vector<bool>> withroach, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (withroach[i][j] == true) {
                if (i+1 < n) {
                    if (grid[i+1][j] != '#')
                        withroach[i+1][j] = true;
                }
                if (i-1 >= 0) {
                    if (grid[i-1][j] != '#')
                        withroach[i-1][j] = true;
                }
                if (j+1 < m) {
                    if (grid[i][j+1] != '#')
                        withroach[i][j+1] = true;
                }
                if (j-1 >= 0) {
                    if (grid[i][j-1] != '#')
                        withroach[i][j-1] = true;
                }
            }
        }
    }
    return withroach;
}

bool get_sandals(vector<vector<char>> grid, pair_ sallypos, pair_ sandalpos, vector<vector<bool>> withroach, int n, int m) {
    if (sallypos.a == sandalpos.a && sallypos.b == sandalpos.b && withroach[sallypos.a][sallypos.b] == false) {
        return true;
    }
    else if (withroach[sallypos.a][sallypos.b] == true) {
        return false;
    }
    else if (grid[sallypos.a][sallypos.b] == '#') {
        return false;
    }
    else {
        vector<vector<bool>> withroachmod;
        withroachmod = expand_roaches(grid, withroach, n, m);
        pair_ recpos;
        bool opt1, opt2, opt3, opt4;
        if (sallypos.a - 1 >= 0) {
            recpos.a = sallypos.a - 1;
            recpos.b = sallypos.b;
            opt1 = get_sandals(grid, recpos, sandalpos, withroachmod, n, m);
        }

        if (sallypos.a + 1 < n) {
            recpos.a = sallypos.a + 1;
            recpos.b = sallypos.b;
            opt2 = get_sandals(grid, recpos, sandalpos, withroachmod, n, m);
        }

        if (sallypos.b - 1 >= 0) {
            recpos.a = sallypos.a;
            recpos.b = sallypos.b - 1;
            opt3 = get_sandals(grid, recpos, sandalpos, withroachmod, n, m);
        }

        if (sallypos.b + 1 < m) {
            recpos.a = sallypos.a;
            recpos.b = sallypos.b + 1;
            opt4 = get_sandals(grid, recpos, sandalpos, withroachmod, n, m);
        }
        return opt1 || opt2 || opt3 || opt4;
    }
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m)); //store input
        vector<vector<bool>> withroach(n, vector<bool>(m, false)); //store input
        pair_ sandalpos, sallypos;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                char next;
                cin >> next;
                if (next == 'S') {
                    // pair_ sallypos;
                    sallypos.a = j;
                    sallypos.b = k;
                }
                else if (next == 'X') {
                    // pair_ sandalpos;
                    sandalpos.a = j;
                    sandalpos.b = k;
                }
                else if (next == '*') {
                    withroach[j][k] = true;
                }
                grid[j][k] = next;
            }
        }

        bool got_sandals = false;
        got_sandals = get_sandals(grid, sallypos, sandalpos, withroach, n, m);
        cout << got_sandals << '\n';
    }

    // cout << got_sandals;
    return 0;
}
