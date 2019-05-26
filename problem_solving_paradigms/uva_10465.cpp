#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main () {
    int m, n, t;
    while (scanf("%d %d %d", &m, &n, &t) != EOF) {
        int smaller = min (m, n);
        int bigger = max (m, n);
        bool no_need_for_beer = false;

        if ((t % smaller) == 0) {
            printf("%d\n", t/smaller);
            no_need_for_beer = true;
        }
        else {
            int reference = (t/smaller)*smaller;
            int min_mod = 100000000;
            int reference_min_mod;
            while (reference >= 0) {
                int mod = (t - reference) % bigger;
                if (mod == 0) {
                    printf("%d\n", reference/smaller + (t - reference)/bigger);
                    no_need_for_beer = true;
                    break;
                }
                else {
                    if (mod < min_mod) {
                        min_mod = mod;
                        reference_min_mod = reference;
                    }
                    reference -= smaller;
                }
            }
            if (no_need_for_beer == false) printf("%d %d\n", reference_min_mod/smaller + (t-reference_min_mod)/bigger, min_mod);
        }
    }
    return 0;
}
