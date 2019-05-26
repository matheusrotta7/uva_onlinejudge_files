#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 200005

int main () {

    vector<int> occur(MAX_SIZE, 0);
    int n;
    cin >> n;
    int maximus = 0;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        int check = ++occur[cur];
        maximus = max(check, maximus);
    }
    if (maximus > 2) {
        cout << "NO\n";
        goto end;
    }
    else {
        vector<int> si; //strictly increasing
        vector<int> sd; //st. decreasing

        for (int i = 0; i < MAX_SIZE; i++) {

            if (occur[i] > 0) {
                occur[i]--;
                si.push_back(i);
            }

        }

        for (int i = MAX_SIZE-1; i >= 0; i--) {

            if (occur[i] > 0) {
                occur[i]--;
                sd.push_back(i);
            }

        }

        //print logic:
        int si_len = si.size();
        int sd_len = sd.size();

        cout << "YES" << '\n';
        cout << si_len << '\n';
        for (int i = 0; i < si_len; i++) {
            if (i != 0)
                cout << ' ';

            cout << si[i];
        }
        cout << '\n';
        cout << sd_len << '\n';
        for (int i = 0; i < sd_len; i++) {
            if (i != 0)
                cout << ' ';

            cout << sd[i];
        }
        cout << '\n';

    }

    int dummy;
    end:
    dummy = 42;
    return 0;
}
