#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000000005

long long int num_of_2s = 0; //yet to be used
long long int num_of_5s = 0; //yet to be used

long long int increase_in_0s(long long int k) {
    bool cont = true;
    while (cont) {
        cont = false;
        if (k % 2 == 0) {
            num_of_2s++;
            k = k/2;
            cont = true;
        }

        if (k % 5 == 0) {
            num_of_5s++;
            k = k/5;
            cont = true;
        }
    }
    long long int num_of_0s = max(num_of_2s, num_of_5s);
    num_of_2s -= num_of_0s;
    num_of_5s -= num_of_0s;
    return num_of_0s;
}

int main () {

    int t;
    cin >> t;


    vector<long long int> z(MAX_SIZE, -1);
    long long int lc; //last calculated
    lc = 0;

    z[1] = 0;

    for (int i = 0; i < t; i++) {
        long long int n;
        cin >> n;

        if (lc >= n) {
            cout << z[n];
        }
        else {
            long long int k;
            for (k = lc+1; k <= n; k++) {
                z[k] = z[k-1] + increase_in_0s(k);
            }
            lc = n;
            cout << z[n] << '\n';
        }

    }



    return 0;
}
