#include<bits/stdc++.h>

using namespace std;

int main() {

    long int n;
    cin >> n;
    while (n != 0) {

        while (true) {
            int acc = 0;
            while (n > 0) {
                acc += n%10;
                n = n/10;
            }
            if (acc > 9)
                n = acc;
            else {
                n = acc;
                break;
            }
        }
        cout << n << '\n';

        cin >> n;
    }

    return 0;
}
