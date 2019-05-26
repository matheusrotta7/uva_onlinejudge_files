#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int iter = 1;
    while (n != 0) {
        vector<int> v;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
            total += a;
        }
        int ref = total/n;
        int divergence = 0;
        for (int i = 0; i < n; i++) {
            divergence += abs(ref - v[i]);
        }
        divergence /= 2;
        cout << "Set #" << iter++ << "\nThe minimum number of moves is " << divergence << ".\n\n";
        cin >> n;
    }

    return 0;
}
