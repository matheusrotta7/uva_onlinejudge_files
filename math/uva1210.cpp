#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> primes;
    primes.push_back(2);
    // cout << '2' << '\n';
    for (int i = 3; i <= 10000; i++) {
        bool is_prime = true;
        for (int j = 0; j < primes.size(); j++) {
            if ((i % primes[j]) == 0) is_prime = false;
        }
        if (is_prime) {
            primes.push_back(i);
            // cout << i << '\n';
        }
    }
    int cur;
    cin >> cur;
    while (cur != 0) {
        int low = 0;
        int high = 0;
        int value = 2;
        int counter = 0;
        while (high <= cur) {
            if (value == cur) {
                counter++;
                high++;
                value += primes[high];
            }
            else if (value > cur) {
                value -= primes[low];
                low++;
            }
            else { //value < cur
                high++;
                value += primes[high];
            }
        }
        cout << counter << '\n';
        cin >> cur;
    }

    return 0;
}
