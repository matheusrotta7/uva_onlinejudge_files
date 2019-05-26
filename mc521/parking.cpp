#include<bits/stdc++.h>

using namespace std;

int main() {


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int small = 999999;
        int big = -999999;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int cur;
            cin >> cur;
            small = min(cur, small);
            big = max(cur, big);
        }
        cout << (big - small)*2 << '\n';
    }

    return 0;
}
