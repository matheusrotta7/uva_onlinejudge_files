#include<bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);

        //silly bruteforce
        int acc = 0;
        for (int j = 1; j < m; j++) {
            if (!(m % j))
                acc += j;
        }
        printf("%d\n", acc);
    }


    return 0;
}
