#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>

#define SIZE 1000000001

using namespace std;

int main () {
    int c; //number of test cases
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n);
        int* v = (int*) malloc(n*sizeof(int));
        for (int j = 0; j < n; j++) scanf("%d", &v[j]);
        int max = 0;
        for (int k = 0; k < n; k++) {
            bool* check = (bool*) calloc(SIZE, sizeof(bool));
            int num_flakes = 0;
            for (int l = k; l < n; l++) {
                if (check[v[l]]) {
                    //we've found a repeated snowflake
                    if (num_flakes > max) max = num_flakes;
                    break;
                }
                else {
                    check[v[l]] = true;
                    num_flakes++;
                }
            }
            free(check);
        }
        printf("%d\n", max);
        free(v);
    }
    return 0;
}
