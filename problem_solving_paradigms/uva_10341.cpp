#include <stdio.h>
#include <cmath>

#define EPS 1e-9
#define result_EPS 1e-7

double test (double x, int p, int q, int r, int s, int t, int u) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main () {
    int p, q, r, s, t, u;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        double lo = 0.0, hi = 1.0, mid = 0.0, result;
        while (fabs(hi-lo) > EPS) {
            mid = (hi + lo)/2.0;
            result = test (mid, p, q, r, s, t, u);
            if (result > 0) {
                lo = mid;
            }
            else if (result < 0) {
                hi = mid;
            }
            else if (result == 0) break;
        }
        if (fabs(result) > result_EPS) printf("No solution\n");
        else printf("%.4lf\n", mid);
    }
    return 0;
}
