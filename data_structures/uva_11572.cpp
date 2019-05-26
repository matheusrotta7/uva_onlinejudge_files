#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <map>

using namespace std;

int main () {
    int c; //number of test cases
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n); //number of snowflakes
        int* v = (int*) malloc(n*sizeof(int));
        int maximum = 0;
        int aux_inic = 0;
        // int aux_final = 0;
        map<int, bool> package;
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
            pair<int, bool> snowflake = pair<int, bool>(v[j], false);
            if(!(package.insert(snowflake)).second) { //repeated snowflake, was not inserted
                maximum = max ((int)package.size(), maximum);
                while (v[aux_inic] != v[j]) {
                    package.erase(v[aux_inic]);
                    aux_inic++;
                }
                package.erase(v[aux_inic++]);
            }
            package.insert(snowflake);
        }
        maximum = max ((int)package.size(), maximum);
        printf("%d\n", maximum);
        free(v);
    }
    return 0;
}
