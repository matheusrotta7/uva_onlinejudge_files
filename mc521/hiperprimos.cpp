#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 2000005
#define TRUST 20

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




    int hp[MAXSIZE];
    int lc = 2;
    hp[2] = 1;

    int n;
    while (scanf("%d\n", &n)!=EOF) {
        if (n > lc) {
            for (int i = lc+1; i <= n; i++) {
                bool is_hp = false;
                int num_of_divisors = 0;
                for (int j = 1; j <= i; j++) {
                    if (i%j == 0)
                        num_of_divisors++;
                }
                if (is_prime(num_of_divisors)) {
                    hp[i] = hp[i-1] + 1;
                }
                else {
                    hp[i] = hp[i-1];
                }
            }
        }
        cout << hp[n] << '\n';
    }


    return 0;
}
