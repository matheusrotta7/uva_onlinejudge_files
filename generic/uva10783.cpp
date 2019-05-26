#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_of_tests;
    cin >> num_of_tests;
    for (int i = 0; i < num_of_tests; i++) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int j = a; j <= b; j++) {
            if ((j % 2) == 1) sum += j;
        }
        cout << "Case " << i+1 << ": " << sum << '\n';
    }
    return 0;
}
