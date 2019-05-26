#include <bits/stdc++.h>

using namespace std;

int main() {
    bool verify[3001];
    int n;
    while (scanf("%d", &n) != EOF) {
        int a, b;
        cin >> a;
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            verify[i] = false;
        }
        for (int i = 1; i < n; i++) {
            cin >> b;
            int dif = abs(a-b);
            if (dif >= 1 && dif <= n-1 && verify[dif] == false) {
                verify[dif] = true;
            }
            else {
                jolly = false;
            }
            a = b;
        }
        if (jolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
