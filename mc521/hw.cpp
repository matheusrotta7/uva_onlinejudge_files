#include<bits/stdc++.h>

using namespace std;

int main() {

    long int n;
    cin >> n;
    long int caso = 0;
    while (n >= 0) {
        caso++;
        if (n == 0) {
            cout << "Case " << caso << ": " << '0' << '\n';
        }
        else {
            long int power = 1;
            int count = 0;
            while (power < n) {
                count++;
                power =  power*2;
            }
            cout << "Case " << caso << ": " << count << '\n';
        }

        cin >> n;
    }

    return 0;
}
