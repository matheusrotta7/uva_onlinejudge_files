#include <bits/stdc++.h>

using namespace std;

int main () {

    long int a, b;
    while (scanf("%ld %ld", &a, &b) != EOF) {
        printf("%ld\n", abs(a - b));
    }
    return 0;
}
