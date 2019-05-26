#include<bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m, save_m;
        scanf("%d", &m);
        save_m = m;
        if (m == 1) {
            printf("0\n");
            continue;
        }
        //less ineficient bruteforce
        int acc = 0;
        int sqrt_m = sqrt(m);
        for (int j = 1; j <= sqrt_m; j++) {
            if (!(m % j)) {
                acc += j;
                int aux;
                if ((aux = m/j) != j && j != 1)
                    acc += aux;
            }

        }
        printf("%d\n", acc);
    }


    return 0;
}
