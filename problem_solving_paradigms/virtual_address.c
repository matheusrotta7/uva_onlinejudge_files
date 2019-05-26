#include <stdio.h>


int main () {
    int staticVar = 0;
    staticVar++;

    sleep(10);
    printf("Address: %x; Value: %d\n", &staticVar, staticVar);

    return 0;
}
