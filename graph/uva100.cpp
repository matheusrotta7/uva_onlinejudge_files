#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int max_n = -1;
        int counter;
        int c, d;
        if (a > b) {
            d = a;
            c = b;
        }
        else {
            c = a;
            d = b;
        }
        for (int j = c; j <= d; j++) {
            int i = j;
            counter = 0;
            while (true) {
                counter++;
                if (i == 1) break;
                if ((i % 2) == 0) i = i/2;
                else i = 3*i + 1;
            }
            max_n = max(max_n, counter);
        }
        printf("%d %d %d\n", a, b, max_n);
    }
    return 0;
}
