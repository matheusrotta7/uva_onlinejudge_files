#include<bits/stdc++.h>

using namespace std;

// long power (long base, long exponent) {
//
//     long result = 1;
//     for (long i = 0; i < exponent; i++) {
//         result *= base;
//     }
//
//     return result;
// }


long potencia (long x, long p) {
    if (p == 0)
        return 1;
    else
        return x * potencia (x, p−1);
}

long potencia2 (long x, long p) {
    long aux;
    if (p == 0)
        return 1;
    else if (p % 2 == 0) {
        aux = potencia (x , p/2);
        return aux*aux;
    } else {
        aux = potencia (x , (p−1)/2);
        return x*aux*aux;
    }
}

int main() {


    long n;
    cin >> n;


    long sum = 0;

    for (long i = 0; i < n; i++) {

        sum += (long)20 * (potencia((long)3, (long)(3*n-3)) - (long)(20 * i));

    }

    long num = (long) potencia((long)10,(long) 9) + (long)7;

    cout << sum % num << '\n';

    return 0;
}
