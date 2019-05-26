#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> primes;
    primes.push_back(2);
    cout << '2' << '\n';
    for (int i = 3; i <= 1000000; i++) {
        bool is_prime = true;
        for (int j = 0; j < primes.size(); j++) {
            if ((i % primes[j]) == 0) is_prime = false;
        }
        if (is_prime) {
            primes.push_back(i);
            cout << i << '\n';
        }
    }

    return 0;
}
