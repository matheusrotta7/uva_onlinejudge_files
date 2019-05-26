#include <stdio.h>
#include <cmath>

int main () {
    long long int N, K;
    long long int num = 1, denom = 1;
    while (1) {
        scanf("%lld %lld", &N, &K);
	if (N == 0 && K == 0) break;
	num = 1;
	denom = 1;
        for (long long int i = N+1; i <= N+K-1; i++) num *= i;
        for (long long int i = 1; i <= K-1; i++) denom *= i;
        printf("%lld\n", num/denom);
    }
    return 0;
}
