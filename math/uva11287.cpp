#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long int n) {
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    long long int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i = i + 6;
    }
    return true;
}


int main() {
    // bool prime_mem[1000000];
    // for (int i = 0; i < 1000000; i++) {
    //     prime_mem[i] = is_prime(i);
    // }
    long long int p, a;
    cin >> p >> a;
    while (a != 0 && p != 0) {
        cout << ((((long long int)pow(a, p) % p) == a) && !is_prime(p) ? "yes\n" : "no\n");
        cin >> p >> a;
    }
    return 0;
}
