#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_of_tests;
    cin >> num_of_tests;
    for (int i = 0; i < num_of_tests; i++) {
        int farmers;
        cin >> farmers;
        int sum = 0;
        for (int j = 0; j < farmers; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            sum += a*c;
        }
        cout << sum << '\n';
    }
    return 0;
}
