#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    while (n != 0) {
        cout << "f91(" << n << ") = " << ((n > 100)? n - 10: 91) << '\n';
        cin >> n;
    }

    return 0;
}
