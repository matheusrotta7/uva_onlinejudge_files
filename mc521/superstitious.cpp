#include<bits/stdc++.h>

using namespace std;

int main () {

    int a, b;
    int yo = 0;

    while (scanf("%d %d\n", &a,&b)!=EOF) {
        int counter = 0;
        for (int i = a; i <= b; i++) {
            int aux = i;
            vector<int> dig(10, 0);
            while (aux != 0) {
                int cur = aux%10;
                dig[cur]++;
                if (dig[cur] == 2) {
                    goto next; //dont increment number of houses and proceed
                }
                aux /= 10;
            }
            counter++;
            next:
            yo++;
        }
        cout << counter << '\n';
    }



    return 0;
}
