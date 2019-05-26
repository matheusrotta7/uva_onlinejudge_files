#include <bits/stdc++.h>

using namespace std;

int sum_of_digits (int n) {
    int ac = 0;
    while (n != 0) {
        ac += n % 10;
        n = n / 10;
    }
    return ac;
}

int main() {

    int n;
    cin >> n;

    while (n != 0) {

        while ((n = sum_of_digits(n)) >= 10) {

        }
        cout << n << '\n';
        cin >> n;
    }

    return 0;
}
