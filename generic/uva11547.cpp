#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        n = (n*63 + 7492)*5 - 498;
        n = abs(n);
        n = n/10;
        n = n%10;
        cout << n << '\n';
    }

    return 0;
}
