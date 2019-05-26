#include<bits/stdc++.h>

using namespace std;

int main() {


    int n, d;
    cin >> n >> d;
    while (n != 0 || d != 0) {
        cout << n/d << ' ' << n%d << ' ' << '/' << ' ' << d << '\n';
        cin >> n >> d;
    }


    return 0;
}
