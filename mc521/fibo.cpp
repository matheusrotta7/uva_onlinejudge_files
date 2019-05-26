#include<bits/stdc++.h>

using namespace std;

typedef struct my_pair {
    int a;
    int b;
} my_pair;

int main () {

    int k;
    cin >> k;
    vector<my_pair> fibo(k+1);
    fibo[0].a = 1;
    fibo[0].b = 0;
    for (int i = 1; i < k+1; i++) {
        fibo[i].a = fibo[i-1].b;
        fibo[i].b = fibo[i-1].b + fibo[i-1].a;
    }
    cout << fibo[k].a << ' ' << fibo[k].b;




    return 0;
}
