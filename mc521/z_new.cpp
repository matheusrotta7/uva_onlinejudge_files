#include<bits/stdc++.h>

using namespace std;


int main () {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long int n;
        cin >> n;

        long long int res;
        res = n/244140625 + n/48828125 + n/9765625 + n/1953125 + n/390625 + n/78125 + n/15625 + n/3125 + n/625 + n/125 + n/25 + n/5;
        cout << res << '\n';
    }



    return 0;
}
