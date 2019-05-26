#include <bits/stdc++.h>

using namespace std;

int main () {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        int* bets = (int*) malloc (n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &bets[i]);
        }

        for (int i = 0; i < n-1; i++) {
            bets[i+1] = max(bets[i+1], bets[i+1] + bets[i]);
        }

        int maximum = bets[0];
        for (int i = 1; i < n; i++) {
            maximum = max(maximum, bets[i]);
        }

        if (maximum < 1) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", maximum);

        free(bets);
    }
    return 0;
}
