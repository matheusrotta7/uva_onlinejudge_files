#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 2000005
#define TRUST 1000

unordered_set<int> small_primes;

bool is_prime (int n) {
    if (n <= 11) {
        if (small_primes.find(n) != small_primes.end()) {
            return true;
        }
        else {
            return false;
        }
    }

    for (int i = 0; i < TRUST; i++) {
        int a = rand() % n;
        // cout << "THIS IS A: " << a << '\n';
        long long int aux = (long long int)pow (a, n-1);
        long long int resto = aux % n;
        if (resto != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    // small_primes.insert(1);
    small_primes.insert(2);
    small_primes.insert(3);
    small_primes.insert(5);
    small_primes.insert(7);
    small_primes.insert(11);
    cout << "73 is prime? Answer: " << is_prime(73) << '\n';
    

    return 0;
}
