#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 500010
#define MODULO 100000007

int main () {


    vector<long long int> fibo(MAX_SIZE, -1);

    int lc = 0;
    fibo[1] = 1;
    fibo[2] = 1;

    lc = 2;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        if (lc >= n) {
            // cout << fibo[n]  << '\n';
            printf("%lld\n", fibo[n]);
        }
        else {
            for (int j = lc + 1; j <= n; j++) {
                fibo[j] = (fibo[j-1] + fibo[j-2]) % MODULO;
            }
            lc = n;
            // cout << (fibo[n] = fibo[n] % MODULO) << '\n';
            printf("%lld\n", fibo[n]);

        }
    }

    return 0;
}
