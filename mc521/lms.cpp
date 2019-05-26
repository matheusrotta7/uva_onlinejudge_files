#include<bits/stdc++.h>

using namespace std;

int main() {

    long long int n;
    cin >> n;

    vector<long long int> kills(n);
    vector<long long int> kills_inc(n);

    long long int sum = 0;

    for (long long int i = 0; i < n; i++) {
        long long int cur;
        cin >> cur;
        sum += cur;
        kills[i] = cur;
    }

    for (long long int i = 0; i < n; i++) {
        kills_inc[n-i-1] = kills[i]; //kills_inc is sorted in non-decreasing order
    }
    bool killing_happens = false;
    long long int first_player;
    for (long long int i = 0; i < n; i++) {
        if (kills_inc[i] != 0) {
            killing_happens = true;
            first_player = n-i;
            break;
        }
    }





    if (sum >= n) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        long long int cur_killer = first_player;
        long long int cur_killed = n;
        for (long long int i = 0; i < sum; i++) {
            cout << cur_killer << ' ' << cur_killed-- << '\n';
            if (--kills_inc[n-cur_killer] == 0) {
                cur_killer--;
            }
        }
    }

    return 0;
}
