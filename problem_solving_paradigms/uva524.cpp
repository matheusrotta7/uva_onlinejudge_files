#include<bits/stdc++.h>

using namespace std;

void find_solutions (int n, vector<vector<vector<int>>> &solutions, vector<bool> prime, int cur, vector<int> ring, vector<bool> used) {
    if (cur == n) {
        if (prime[ring[cur-1]+1]) {
            solutions[n].push_back(ring);
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!used[i-1]) {
            if (prime[ring[cur-1]+i]) {
                ring[cur] = i;
                used[i-1] = true;
                find_solutions(n, solutions, prime, cur+1, ring, used);
                used[i-1] = false;
            }
        }
    }

}

int main() {

    vector<bool> prime(40, false);
    prime[1] = true;
    prime[2] = true;
    prime[3] = true;
    prime[5] = true;
    prime[7] = true;
    prime[11] = true;
    prime[13] = true;
    prime[17] = true;
    prime[19] = true;
    prime[23] = true;
    prime[29] = true;
    prime[31] = true;
    vector<vector<vector<int>>> solutions(20);
    solutions[1].push_back(vector<int>(1, 1));
    for (int i = 2; i <= 16; i++) {
        vector<int> ring(i, -1);
        vector<bool> used(i, false);
        ring[0] = 1;
        used[0] = true;
        find_solutions(i, solutions, prime, 1, ring, used);
    }

    int n;
    int m = 1;
    while (scanf("%d", &n)!=EOF) {
        if (m!=1)
            cout << '\n';
        printf("Case %d:\n", m++);
        for (int i = 0; i < solutions[n].size(); i++) {
            for (int j = 0; j < solutions[n][i].size(); j++) {
                if (j!=0)
                    cout << ' ';
                cout << solutions[n][i][j];
            }
            cout << '\n';
        }
    }


    return 0;
}
