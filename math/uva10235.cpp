#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i = i + 6;
    }
    return true;
}

int reverse (int n) {
    int m = 0;
    stack<int> q;
    while (n != 0) {
        q.push(n % 10);
        n /= 10;
    }
    int counter = 0;
    while (!q.empty()) {
        m += q.top() * pow (10, counter++);
        q.pop();
    }
    return m;
}


int main() {
    // bool prime_mem[1000000];
    // for (int i = 0; i < 1000000; i++) {
    //     prime_mem[i] = is_prime(i);
    // }
    int n;
    while (scanf("%d", &n) != EOF) {
        if (!is_prime(n)) printf("%d is not prime.\n", n);
        else {
            int m = reverse(n);
            if ((m == n) || !is_prime(m)) printf("%d is prime.\n", n);
            else printf("%d is emirp.\n", n);
        }
    }
    return 0;
}
