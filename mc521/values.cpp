#include<bits/stdc++.h>

using namespace std;

int total = 0;
int counter = 0;
void combine (vector<vector<int>> values, int cur_line, int j, int n, int acc) {

    counter++;
    // acc = 0;
    if (cur_line == n-1) {
        acc += values[cur_line][j];
        if (acc == 0)
            total++;
        acc = 0;
    }
    else {
        for (int j = 0; j < 4; j++) {
            acc += values[cur_line][j];
            // cout << acc << '\n';
            combine(values, cur_line+1, j, n, acc);
        }
    }

}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> val(n, vector<int>(4, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int aux;
            cin >> aux;
            val[i][j] = aux;
        }
    }

    combine (val, 0, 0, n, 0);
    cout << total << '\n';
    cout << counter << '\n';

    return 0;
}
